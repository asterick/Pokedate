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

extern "C" void flip_screen(void*);

void LCD::reset(LCD::State& lcd) {
	memset(&lcd, 0, sizeof(lcd));
	lcd.volume = 0x20;
}

static inline uint32_t lerp(uint8_t a, uint8_t b, float rt) {
	return (uint8_t)(a * (1.0f - rt) + b * rt);
}

static inline uint32_t contrast(uint32_t color, uint8_t volume) {
	if (volume < 0x20) {
		return lerp(OFF_COLOR, color, volume / 31.0f);
	} if (volume > 0x20) {
		return lerp(color, ON_COLOR, (volume - 0x20) / 31.0f);
	} else {
		return color;
	}
}

static void render(uint8_t (&framebuffer)[LCD_HEIGHT][LCD_WIDTH], LCD::State& lcd, int com) {
	const uint32_t off = contrast(OFF_COLOR, lcd.volume_locked);
	const uint32_t on = contrast(ON_COLOR, lcd.volume_locked);

	if (!lcd.display_enable) {
		memset(&framebuffer[com], off, sizeof(framebuffer[com]));
		return ;
	} else if (lcd.all_on) {
		memset(&framebuffer[com], on, sizeof(framebuffer[com]));
		return ;
	}

	uint8_t* line = framebuffer[lcd.reverse_com_scan ? (63 - com) : com];

	int drawline = (com + lcd.start_address) % 0x40;
	uint8_t mask = 1 << (drawline % 8);
	uint8_t* current_page = lcd.gddram[drawline / 8];

	for (int x = 0; x < LCD_WIDTH; x++) {
		uint8_t byte =  current_page[lcd.adc_select ? 131 - x : x];
		bool set = byte & mask;
			
		*(line++) = (set ? on : off);
	}
}

void LCD::clock(Machine::State& cpu, int osc3) {
	cpu.lcd.overflow += osc3 * LCD_SPEED;

	while (cpu.lcd.overflow >= OSC3_SPEED) {
		if (cpu.lcd.scanline >= 0x40) {
			flip_screen(cpu.lcd.framebuffer);

			cpu.lcd.volume_locked = cpu.lcd.volume;
			cpu.lcd.scanline = 0;
			Blitter::clock(cpu);
		} else {
			render(cpu.lcd.framebuffer, cpu.lcd, cpu.lcd.scanline++);
		}

		cpu.lcd.overflow -= OSC3_SPEED;
	}
}

uint8_t LCD::get_scanline(LCD::State& lcd) {
	return lcd.scanline + 1;
}

uint8_t LCD::read(LCD::State& lcd, uint32_t address) {
	if (address == 0x20FE) {
		return 0;
	} else {
		uint8_t data = lcd.read_buffer;
		
		data = lcd.gddram[lcd.page_address][lcd.column_address];

		if (lcd.column_address < 0x83 && !lcd.rmw_mode) {
			lcd.column_address++;
		}

		return data;
	}
}

void LCD::write(LCD::State& lcd, uint8_t data, uint32_t address) {
	lcd.read_buffer = data;

	if (lcd.setting_volume) {
		lcd.volume = data & 0x3F;
		lcd.setting_volume = false;
		return ;
	}

	if (address == 0x20FE) {
		switch (data) {
		case 0b10101110: case 0b10101111:
			lcd.display_enable = data & 1;
			break ;

		case 0b01000000: case 0b01000001: case 0b01000010: case 0b01000011: case 0b01000100: case 0b01000101: case 0b01000110: case 0b01000111:
		case 0b01001000: case 0b01001001: case 0b01001010: case 0b01001011: case 0b01001100: case 0b01001101: case 0b01001110: case 0b01001111:
		case 0b01010000: case 0b01010001: case 0b01010010: case 0b01010011: case 0b01010100: case 0b01010101: case 0b01010110: case 0b01010111:
		case 0b01011000: case 0b01011001: case 0b01011010: case 0b01011011: case 0b01011100: case 0b01011101: case 0b01011110: case 0b01011111:
		case 0b01100000: case 0b01100001: case 0b01100010: case 0b01100011: case 0b01100100: case 0b01100101: case 0b01100110: case 0b01100111:
		case 0b01101000: case 0b01101001: case 0b01101010: case 0b01101011: case 0b01101100: case 0b01101101: case 0b01101110: case 0b01101111:
		case 0b01110000: case 0b01110001: case 0b01110010: case 0b01110011: case 0b01110100: case 0b01110101: case 0b01110110: case 0b01110111:
		case 0b01111000: case 0b01111001: case 0b01111010: case 0b01111011: case 0b01111100: case 0b01111101: case 0b01111110: case 0b01111111:
			lcd.start_address = data & 0b111111;
			break ;

		case 0b00000000: case 0b00000001: case 0b00000010: case 0b00000011: case 0b00000100: case 0b00000101: case 0b00000110: case 0b00000111:
		case 0b00001000: case 0b00001001: case 0b00001010: case 0b00001011: case 0b00001100: case 0b00001101: case 0b00001110: case 0b00001111:
			lcd.column_address = (lcd.column_address & 0xF0) | (data & 0xF);

			if (lcd.column_address > 0x83) lcd.column_address = 0x83;
			break ;

		case 0b00010000: case 0b00010001: case 0b00010010: case 0b00010011: case 0b00010100: case 0b00010101: case 0b00010110: case 0b00010111:
		case 0b00011000: case 0b00011001: case 0b00011010: case 0b00011011: case 0b00011100: case 0b00011101: case 0b00011110: case 0b00011111:
			lcd.column_address = (lcd.column_address & 0x0F) | (data << 4);

			if (lcd.column_address > 0x83) lcd.column_address = 0x83;
			break ;

		case 0b00100000: case 0b00100001: case 0b00100010: case 0b00100011: case 0b00100100: case 0b00100101: case 0b00100110: case 0b00100111:
			lcd.resistor_ratio = data & 0b111;
			break ;

		case 0b00101000: case 0b00101001: case 0b00101010: case 0b00101011: case 0b00101100: case 0b00101101: case 0b00101110: case 0b00101111:
			lcd.operating_mode = data & 0b111;
			break ;

		case 0b10110000: case 0b10110001: case 0b10110010: case 0b10110011: case 0b10110100: case 0b10110101: case 0b10110110: case 0b10110111:
		case 0b10111000: case 0b10111001: case 0b10111010: case 0b10111011: case 0b10111100: case 0b10111101: case 0b10111110: case 0b10111111:
			lcd.page_address = data & 0xF;

			if (lcd.page_address > 8) lcd.page_address = 8;
			break ;

		case 0b10100000: case 0b10100001:
			lcd.adc_select = data & 1;
			break ;

		case 0b10100110: case 0b10100111:
			lcd.reverse_display = data & 1;
			break ;

		case 0b10100100: case 0b10100101:
			lcd.all_on = data & 1;
			break ;

		case 0b10100010: case 0b10100011:
			lcd.lcd_bias = data & 1;
			break ;

		case 0b10101100:case 0b10101101:
			lcd.static_indicator = data & 1;
			break ;

		case 0b11100000: // Set RMW mode
			lcd.rmw_mode = true;
			break ;

		case 0b11101110: // End
			lcd.rmw_mode = false;
			break ;

		case 0b11000000: case 0b11000001: case 0b11000010: case 0b11000011: case 0b11000100: case 0b11000101: case 0b11000110: case 0b11000111:
		case 0b11001000: case 0b11001001: case 0b11001010: case 0b11001011: case 0b11001100: case 0b11001101: case 0b11001110: case 0b11001111:
			lcd.reverse_com_scan = data & 8;
			break ;

		case 0b10000001: // Set electric volume
			lcd.setting_volume = true;
			break ;
		
		case 0b11100011: // NOP
			break ;
		}
	} else {
		if (lcd.page_address >= 8) data &= 1;

		lcd.gddram[lcd.page_address][lcd.column_address] = data;

		if (lcd.column_address < 0x83) {
			lcd.column_address++;
		}
	}
}
