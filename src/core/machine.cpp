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

#include <stdint.h>
#include <string.h>

#include "machine.h"

void Machine::reset(Machine::State& cpu) {
	cpu.reg.pc = read16(cpu, 0x0000);
	cpu.reg.sc = 0xC0;
	cpu.reg.ep = 0xFF;
	cpu.reg.xp = 0x00;
	cpu.reg.yp = 0x00;
	cpu.reg.nb = 0x01;

	cpu.status = STATUS_NORMAL;
	cpu.osc1_overflow = 0;

	Control::reset(cpu.ctrl);
	IRQ::reset(cpu);
	LCD::reset(cpu.lcd);
	RTC::reset(cpu);
	TIM256::reset(cpu);
	Blitter::reset(cpu);
	Timers::reset(cpu);
	Input::reset(cpu.input);
	GPIO::reset(cpu.gpio);
	Audio::reset(cpu.audio);
}

void Machine::advance(Machine::State& cpu, int ticks) {
	cpu.clocks += ticks;

	while (cpu.clocks > 0) {
		// We have an IRQ Scheduled
		IRQ::manage(cpu);

		// CPU Core steps
		if (cpu.status == STATUS_NORMAL) {
			clock(cpu, inst_advance(cpu));
		}
		else {
			// Eat a cycle
			clock(cpu, 1);
		}
	}
}

void Machine::clock(Machine::State& cpu, int cycles) {
	const int osc3 = cycles * OSC3_SPEED / CPU_SPEED;	
	int osc1 = 0;

	cpu.osc1_overflow += osc3 * OSC1_SPEED;

	if (cpu.status <= STATUS_HALTED) {
		LCD::clock(cpu, osc3);
		Timers::clock(cpu, osc1, osc3);
		Audio::clock(cpu, osc3);

		if (cpu.osc1_overflow >= OSC3_SPEED) {
			// Assume we are not going to get more than a couple ticks out of this thing
			do {
				cpu.osc1_overflow -= OSC3_SPEED;
				osc1++;
			} while (cpu.osc1_overflow >= OSC3_SPEED);

			// These are the devices that only advance with OSC3
			TIM256::clock(cpu, osc1);
			RTC::clock(cpu, osc1);
	 	} else {
	 		osc1 = 0;
	 	}
	}

 	// OSC3 = 4mhz oscillator, OSC1 = 32khz oscillator
	cpu.clocks -= osc3;
}

static inline uint8_t read_reg(Machine::State& cpu, uint32_t address) {
	switch (address & 0xFFF8) {
	case 0x2000:
		return Control::read(cpu.ctrl, address);
	case 0x2008:
		return RTC::read(cpu, address);
	case 0x2020: case 0x2028:
		return IRQ::read(cpu, address);
	case 0x2040:
		return TIM256::read(cpu, address);
	case 0x2050:
		return Input::read(cpu.input, address);
	case 0x2060:
		return GPIO::read(cpu.gpio, address);
	case 0x2070:
		return Audio::read(cpu.audio, address);
	case 0x2010:
		// This should be handled properly
		return 0b010000;
	case 0x20F8:
		if (cpu.ctrl.lcd_enabled) {
			return LCD::read(cpu.lcd, address);
		} else {
			return cpu.bus_cap;
		}
		break ;
	case 0x2080: case 0x2088:
	case 0x20F0:
		return Blitter::read(cpu, address);
	case 0x2018:
	case 0x2030:
	case 0x2048:
		return Timers::read(cpu, address);
	default:
		return cpu.bus_cap;
	}
}

static inline void write_reg(Machine::State& cpu, uint8_t data, uint32_t address) {
	switch (address & 0xFFF8) {
	case 0x2000:
		Control::write(cpu.ctrl, data, address);
		break ;
	case 0x2008:
		RTC::write(cpu, data, address);
		break ;
	case 0x2020: case 0x2028:
		IRQ::write(cpu, data, address);
		break ;
	case 0x2040:
		TIM256::write(cpu, data, address);
		break ;
	case 0x2050:
		Input::write(cpu.input, data, address);
		break ;
	case 0x2060:
		GPIO::write(cpu.gpio, data, address);
		break ;
	case 0x2070:
		Audio::write(cpu.audio, data, address);
		break ;
	case 0x2080: case 0x2088: case 0x20F0:
		Blitter::write(cpu, data, address);
		break ;
	case 0x20F8:
		if (cpu.ctrl.lcd_enabled) {
			LCD::write(cpu.lcd, data, address);
		}
		break ;
	case 0x2018: case 0x2030: case 0x2048:
		Timers::write(cpu, data, address);
		break ;
	default:
		break ;
	}
}

static inline uint8_t read_cart(Machine::State& cpu, uint32_t address) {
    return cpu.cartridge[address % sizeof(cpu.cartridge)];
}

static inline void write_cart(Machine::State& cpu, uint8_t data, uint32_t address) {
}


uint8_t Machine::read(Machine::State& cpu, uint32_t address) {
	if (address >= 0x2100) {
		if (cpu.ctrl.cart_enabled) {
			return cpu.bus_cap = read_cart(cpu, address);
		}
		else {
			return cpu.bus_cap;
		}
	}
	else if (address >= 0x2000) {
		return cpu.bus_cap = read_reg(cpu, address);
	}
	else if (address >= 0x1000) {
		return cpu.bus_cap = cpu.ram[address & 0xFFF];
	}
	else {
		return cpu.bus_cap = cpu.BIOS[address];
	}
}

void Machine::write(Machine::State& cpu, uint8_t data, uint32_t address) {
	cpu.bus_cap = data;
	
	if (address >= 0x2100) {
		if (cpu.ctrl.cart_enabled) {
			write_cart(cpu, data, address);
		}
	}
	else if (address >= 0x2000) {
		write_reg(cpu, data, address);
	}
	else if (address >= 0x1000) {
		cpu.ram[address & 0xFFF] = data;
	}
}

/**
 * S1C88 Memory access helper functions
 **/


uint8_t Machine::read8(Machine::State& cpu, uint32_t address) {
	return cpu.bus_cap = read(cpu, address);
}

void Machine::write8(Machine::State& cpu, uint8_t data, uint32_t address) {
	write(cpu, cpu.bus_cap = data, address);
}

uint16_t Machine::read16(Machine::State& cpu, uint32_t address) {
	uint16_t lo = read8(cpu, address);
	address = ((address + 1) & 0xFFFF) | (address & 0xFF0000);
	return (read8(cpu, address) << 8) | lo;
}

void Machine::write16(Machine::State& cpu, uint16_t data, uint32_t address) {
	write8(cpu, (uint8_t) data, address);
	address = ((address + 1) & 0xFFFF) | (address & 0xFF0000);
	write8(cpu, data >> 8, address);
}

uint8_t Machine::imm8(Machine::State& cpu) {
	auto address = calc_pc(cpu);
	cpu.reg.pc++;

	return read8(cpu, address);
}

uint16_t Machine::imm16(Machine::State& cpu) {
	uint8_t lo = imm8(cpu);
	return (imm8(cpu) << 8) | lo;
}

void Machine::push8(Machine::State& cpu, uint8_t t) {
	write8(cpu, t, --cpu.reg.sp);
}

uint8_t Machine::pop8(Machine::State& cpu) {
	return read8(cpu, cpu.reg.sp++);
}

void Machine::push16(Machine::State& cpu, uint16_t t) {
	push8(cpu, t >> 8);
	push8(cpu, (uint8_t)t);
}

uint16_t Machine::pop16(Machine::State& cpu) {
	uint16_t t = pop8(cpu);
	return (pop8(cpu) << 8) | t;
}
