/*
ISC License

Copyright (c) 2019, Bryon Vandiver

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once

#include <stdint.h>

namespace Machine { struct State; };

#include "lcd.h"
#include "irq.h"
#include "tim256.h"
#include "timers.h"
#include "rtc.h"
#include "blitter.h"
#include "control.h"
#include "input.h"
#include "eeprom.h"
#include "gpio.h"
#include "audio.h"

const auto OSC1_SPEED	= 32768;
const auto OSC3_SPEED	= 4000000;
const auto TICK_SPEED	= 1000;
const auto CPU_SPEED	= 1000000;

namespace CPU {
	struct State {
		union {
			struct {
				uint8_t sc;
				uint8_t cc;
			};

			struct {
				unsigned int z:1;
				unsigned int c:1;
				unsigned int v:1;
				unsigned int n:1;
				unsigned int d:1;
				unsigned int u:1;
				unsigned int i:2;

				unsigned int f0:1;
				unsigned int f1:1;
				unsigned int f2:1;
				unsigned int f3:1;
			} flag;
		};

		union {
			struct {
				uint8_t a;
				uint8_t b;
				uint8_t l;
				uint8_t h;
			};

			struct {
				uint16_t ba;
				uint16_t hl;
			};
		};

		uint16_t pc;
		uint16_t sp;
		uint16_t ix;
		uint16_t iy;

		uint8_t br;
		uint8_t ep;
		uint8_t xp;
		uint8_t yp;

		uint8_t cb;
		uint8_t nb;
	};
};

namespace Machine {
	enum Status : uint8_t {
		STATUS_NORMAL,
		STATUS_HALTED,
		STATUS_SLEEPING,
		STATUS_CRASHED
	};

	struct State {
		CPU::State reg;
		IRQ::State irq;
		LCD::State lcd;
		RTC::State rtc;
		Control::State ctrl;
		TIM256::State tim256;
		Blitter::State blitter;
		Timers::State timers;
		Input::State input;
		GPIO::State gpio;
		Audio::State audio;

		uint8_t bus_cap;
		int clocks;
		int osc1_overflow;
		Status status;

		union {
			uint8_t ram[0x1000];
		 	Blitter::Overlay overlay;
		};

		uint8_t BIOS[0x2000];
		uint8_t cartridge[0x200000];
	};

	// Library functions
	uint8_t read(Machine::State& cpu, uint32_t address);
	void write(Machine::State& cpu, uint8_t data, uint32_t address);
	void reset(Machine::State& cpu);
	void advance(Machine::State& cpu, int ticks);

	// Clock management
	void clock(Machine::State& cpu, int cycles);

	// These are memory access helpers
	uint8_t read8(Machine::State& cpu, uint32_t address);
	void write8(Machine::State& cpu, uint8_t data, uint32_t address);
	uint16_t read16(Machine::State& cpu, uint32_t address);
	void write16(Machine::State& cpu, uint16_t data, uint32_t address);
	uint8_t imm8(Machine::State& cpu);
	uint16_t imm16(Machine::State& cpu);
	void push8(Machine::State& cpu, uint8_t t);
	uint8_t pop8(Machine::State& cpu);
	void push16(Machine::State& cpu, uint16_t t);
	uint16_t pop16(Machine::State& cpu);
}

int inst_advance(Machine::State& cpu);

static inline uint32_t calc_pc(Machine::State& cpu) {
	uint16_t address = cpu.reg.pc;

	if (address & 0x8000) {
		return (cpu.reg.cb << 15) | (address & 0x7FFF);
	} else {
		return address;
	}
}
