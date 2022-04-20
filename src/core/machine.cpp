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

extern "C" uint8_t BIOS[0x2000];
static Machine::State machine_state;

extern "C" void cpu_reset() {
	machine_state.reg.pc = cpu_read16(machine_state, 0x0000);
	machine_state.reg.sc = 0xC0;
	machine_state.reg.ep = 0xFF;
	machine_state.reg.xp = 0x00;
	machine_state.reg.yp = 0x00;
	machine_state.reg.nb = 0x01;

	machine_state.status = Machine::STATUS_NORMAL;
	machine_state.osc1_overflow = 0;

	Control::reset(machine_state.ctrl);
	IRQ::reset(machine_state);
	LCD::reset(machine_state.lcd);
	RTC::reset(machine_state);
	TIM256::reset(machine_state);
	Blitter::reset(machine_state);
	Timers::reset(machine_state);
	Input::reset(machine_state.input);
	GPIO::reset(machine_state.gpio);
	Audio::reset(machine_state.audio);
}

extern "C" uint8_t* get_eeprom(void) {
	return machine_state.gpio.eeprom.data;
}

extern "C" void update_inputs(uint16_t value) {
	Input::update(machine_state, value);
}

extern "C" void set_sample_rate(int rate) {
	Audio::setSampleRate(machine_state.audio, rate);
}

extern "C" int get_audio_samples(int16_t* samples, int len) {
	if (machine_state.audio.write_index < len) {
		return 0;
	}

	memcpy(samples, machine_state.audio.output, len*sizeof(int16_t));
	memcpy(machine_state.audio.output, 
		&machine_state.audio.output[machine_state.audio.write_index], (machine_state.audio.write_index - len) * sizeof(int16_t));
	machine_state.audio.write_index -= len;

	return 1;
}

extern "C" uint8_t * cpu_get_cart() {
	return machine_state.cartridge;
}

extern "C" void cpu_advance(int ticks) {
	machine_state.clocks += ticks;

	while (machine_state.clocks > 0) {

		// We have an IRQ Scheduled
		IRQ::manage(machine_state);

		// CPU Core steps
		if (machine_state.status == Machine::STATUS_NORMAL) {
			cpu_clock(machine_state, inst_advance(machine_state));
		}
		else {
			// Eat a cycle
			cpu_clock(machine_state, 1);
		}
	}
}

void cpu_clock(Machine::State& cpu, int cycles) {
	const int osc3 = cycles * OSC3_SPEED / CPU_SPEED;	
	int osc1 = 0;

	cpu.osc1_overflow += osc3 * OSC1_SPEED;

	if (cpu.status <= Machine::STATUS_HALTED) {
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

static inline uint8_t cpu_read_reg(Machine::State& cpu, uint32_t address) {
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

static inline void cpu_write_reg(Machine::State& cpu, uint8_t data, uint32_t address) {
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

static inline uint8_t cpu_read_cart(Machine::State& cpu, uint32_t address) {
    return cpu.cartridge[address % sizeof(cpu.cartridge)];
}

static inline void cpu_write_cart(Machine::State& cpu, uint8_t data, uint32_t address) {
}


uint8_t cpu_read(Machine::State& cpu, uint32_t address) {
	if (address >= 0x2100) {
		if (cpu.ctrl.cart_enabled) {
			return cpu.bus_cap = cpu_read_cart(cpu, address);
		}
		else {
			return cpu.bus_cap;
		}
	}
	else if (address >= 0x2000) {
		return cpu.bus_cap = cpu_read_reg(cpu, address);
	}
	else if (address >= 0x1000) {
		return cpu.bus_cap = cpu.ram[address & 0xFFF];
	}
	else {
		return cpu.bus_cap = BIOS[address];
	}
}

void cpu_write(Machine::State& cpu, uint8_t data, uint32_t address) {
	cpu.bus_cap = data;
	
	if (address >= 0x2100) {
		if (cpu.ctrl.cart_enabled) {
			cpu_write_cart(cpu, data, address);
		}
	}
	else if (address >= 0x2000) {
		cpu_write_reg(cpu, data, address);
	}
	else if (address >= 0x1000) {
		cpu.ram[address & 0xFFF] = data;
	}
}

/**
 * S1C88 Memory access helper functions
 **/


uint8_t cpu_read8(Machine::State& cpu, uint32_t address) {
	return cpu.bus_cap = cpu_read(cpu, address);
}

void cpu_write8(Machine::State& cpu, uint8_t data, uint32_t address) {
	cpu_write(cpu, cpu.bus_cap = data, address);
}

uint16_t cpu_read16(Machine::State& cpu, uint32_t address) {
	uint16_t lo = cpu_read8(cpu, address);
	address = ((address + 1) & 0xFFFF) | (address & 0xFF0000);
	return (cpu_read8(cpu, address) << 8) | lo;
}

void cpu_write16(Machine::State& cpu, uint16_t data, uint32_t address) {
	cpu_write8(cpu, (uint8_t) data, address);
	address = ((address + 1) & 0xFFFF) | (address & 0xFF0000);
	cpu_write8(cpu, data >> 8, address);
}

uint8_t cpu_imm8(Machine::State& cpu) {
	auto address = calc_pc(cpu);
	cpu.reg.pc++;

	return cpu_read8(cpu, address);
}

uint16_t cpu_imm16(Machine::State& cpu) {
	uint8_t lo = cpu_imm8(cpu);
	return (cpu_imm8(cpu) << 8) | lo;
}

void cpu_push8(Machine::State& cpu, uint8_t t) {
	cpu_write8(cpu, t, --cpu.reg.sp);
}

uint8_t cpu_pop8(Machine::State& cpu) {
	return cpu_read8(cpu, cpu.reg.sp++);
}

void cpu_push16(Machine::State& cpu, uint16_t t) {
	cpu_push8(cpu, t >> 8);
	cpu_push8(cpu, (uint8_t)t);
}

uint16_t cpu_pop16(Machine::State& cpu) {
	uint16_t t = cpu_pop8(cpu);
	return (cpu_pop8(cpu) << 8) | t;
}
