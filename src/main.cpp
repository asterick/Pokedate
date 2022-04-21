//
//  main.c
//  Extension
//
//  Created by Dave Hayden on 7/30/14.
//  Copyright (c) 2014 Panic, Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "machine.h"

using namespace Machine;

static Machine::State machine_state;

extern "C" {
	#include "pd_api.h"
};

static const int DISPLAY_ROW_STRIDE = 52;
#define BOX_CELLS 4

static PlaydateAPI* pd = NULL;
static unsigned int last_time;
static int power_pressed;

static const uint8_t dither[4][4] = {
	{  15, 195,  60, 240 },
	{ 135,  75, 180, 120 },
	{  45, 225,  30, 210 },
	{ 165, 105, 150,  90 },
};

static int audioSource(void* context, int16_t* samples, int16_t* _, int len) {
	static int read_index = 0;
	int write_index = machine_state.audio.write_index;

	// Determine how many frames are in our audio buffer
	int frames = write_index - read_index;
	if (frames < 0) frames += AUDIO_BUFFER_LENGTH;

	// Not enough, return
	if (frames < len) {
		return 0;
	}

	if (read_index + len > AUDIO_BUFFER_LENGTH) {
		// We need to split the copy
		int top = AUDIO_BUFFER_LENGTH - write_index;
		int bottom = len - top;

		memcpy(samples, &machine_state.audio.output[read_index], top);
		memcpy(samples, &machine_state.audio.output[0], bottom);
	} else {
		// Simple copy
		memcpy(samples, &machine_state.audio.output[read_index], len);
	}

	read_index = (read_index + len) % AUDIO_BUFFER_LENGTH;

	return 1;
}

void upsample(uint8_t* in, uint8_t* out) {
	in += 96+3;
	for (int row = 0; row < 64; row++) {
		for (int col = 0; col < 96; col++) {
			out[0] = out[1] = out[2] =
			out[96 * 3 + 0] = out[96 * 3 + 1] = out[96 * 3 + 2] =
			out[96 * 6 + 0] = out[96 * 6 + 1] = out[96 * 6 + 2] = *(in++);
			out += 3;
		}
		out += 96*2*3;
		in += 2;
	}
}

extern "C" void flip_screen(uint8_t* frame_data) {

	// Do a 4 cell box average
	static uint8_t box[BOX_CELLS][64*96] = { {0} };
	static uint8_t sum[66][98] = {0};
	static int frame_idx = 0;
	uint8_t* box_filter = box[frame_idx];
	uint8_t* sum_filter = &sum[1][1];
		frame_idx = (frame_idx + 1) % 4;

	for (int row = 1; row <= 64; row++) {
		for (int col = 0; col < 96; col++) {
			*(sum_filter++) += *frame_data - *box_filter;
			*(box_filter++) = *(frame_data++);
		}
		sum_filter += 2;
	}

	// Upscale our image
	uint8_t upscale[64 * 3][96 * 3];
	upsample(&sum[0][0], &upscale[0][0]);

	// Dither to display
	uint8_t* frame = pd->graphics->getFrame();
	uint8_t* draw_target = &frame[52 * (240 - 64 * 3) / 2 + (400 - 96 * 3) / 8 / 2];
	uint8_t* source = &upscale[0][0];

	if (frame == NULL) return;

	for (int y = 0; y < 64 * 3; y++) {
		for (int x = 0; x < 96 * 3; x += 8) {
			uint8_t byte = 0;

			for (uint8_t b = 0; b < 8; b++) {
				if (*(source++) - dither[(x+b) & 3][y & 3] >= 0) byte |= 0x80 >> b;
			}

			*(draw_target++) = byte;
		}
		draw_target += (400 - (96 * 3)) / 8 + 2;
	}

	pd->graphics->markUpdatedRows(0, 240);
}

static void initialize(void)
{
	// Configure emulator
	Audio::setSampleRate(machine_state.audio, 44100);
	last_time = pd->system->getCurrentTimeMilliseconds();

	// Load BIOS image
	SDFile* fd = pd->file->open("bios.rom", kFileRead);

	if (fd == NULL) {
		pd->system->logToConsole("bios.rom not found");
		return;
	}

	pd->file->read(fd, machine_state.BIOS, sizeof(machine_state.BIOS));
	pd->file->close(fd);

	// Restore EEPROM
	fd = pd->file->open("eeprom.bin", kFileReadData);
	if (fd != NULL) {
		pd->file->read(fd, machine_state.gpio.eeprom.data, 0x2000);
		pd->file->close(fd);
	}

	Machine::reset(machine_state);
}

static void preserve(void) {
	SDFile* fd = pd->file->open("eeprom.bin", kFileWrite);
	if (fd != NULL) {
		pd->file->write(fd, machine_state.gpio.eeprom.data, 0x2000);
		pd->file->close(fd);
	}
	else {
		pd->system->logToConsole("Could not save eeprom");
	}
}

static void detectShake(void) {
	float x, y, z;
	pd->system->getAccelerometer(&x,&y,&z);
	pd->system->logToConsole("%f %f %f", x, y, z);
}

static void pressPower(void* userdata) {
	power_pressed = 100;
}

int reset(lua_State *L) {
	Machine::reset(machine_state);
	return 0;
}

int load(lua_State *L) {
	return 0;
}

int eject(lua_State *L) {
	return 0;
}

int step(lua_State *L) {
	// Calculate elapsed time
	unsigned int ms = pd->lua->getArgInt(1);
	unsigned int ticks = ms * OSC3_SPEED / 1000;

	// Update inputs
	uint16_t input_state = 0b0111111111;
	PDButtons pushed;
	pd->system->getButtonState(&pushed, NULL, NULL);

	if (pushed & kButtonA)     input_state &= ~0b00000001;
	if (pushed & kButtonB)     input_state &= ~0b00000010;
	if (pd->system->isCrankDocked()) input_state &= ~0b00000100;
	if (pushed & kButtonUp)    input_state &= ~0b00001000;
	if (pushed & kButtonDown)  input_state &= ~0b00010000;
	if (pushed & kButtonLeft)  input_state &= ~0b00100000;
	if (pushed & kButtonRight) input_state &= ~0b01000000;
	
	if (power_pressed > 0) {
		input_state &= ~0b10000000;
		power_pressed -= ms;
	}
	Input::update(machine_state, input_state);

	detectShake();
	Machine::advance(machine_state, ticks);

	return 0;
}

#ifdef _WINDLL
__declspec(dllexport)
#endif
int eventHandler(PlaydateAPI* playdate, PDSystemEvent event, uint32_t arg)
{
	switch (event) {
	case kEventInit:
		pd = playdate;
		pd->display->setRefreshRate(0); // run as fast as possible
		pd->system->setPeripheralsEnabled(kAccelerometer);
		pd->system->addMenuItem("Press Power", pressPower, NULL);
		pd->sound->addSource(audioSource, NULL, 0);

		initialize();
		break ;

	case kEventInitLua:
		const char* err;

		pd->lua->addFunction(step, "minimon.step", &err);
		if (err) pd->system->error("Cannot add function: %s", err);
		pd->lua->addFunction(reset, "minimon.reset", &err);
		if (err) pd->system->error("Cannot add function: %s", err);
		pd->lua->addFunction(load, "minimon.load", &err);
		if (err) pd->system->error("Cannot add function: %s", err);
		pd->lua->addFunction(eject, "minimon.eject", &err);
		if (err) pd->system->error("Cannot add function: %s", err);

		break;

	case kEventTerminate:
	case kEventPause:
	case kEventLowPower:
		preserve();
		break ;

	default:
		break  ;
	}
	
	return 0;
}
