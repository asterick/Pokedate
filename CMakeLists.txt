cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 11)

set(ENVSDK $ENV{PLAYDATE_SDK_PATH})

if (NOT ${ENVSDK} STREQUAL "")
	# Convert path from Windows
	file(TO_CMAKE_PATH ${ENVSDK} SDK)
else()
	execute_process(
			COMMAND bash -c "egrep '^\\s*SDKRoot' $HOME/.Playdate/config"
			COMMAND head -n 1
			COMMAND cut -c9-
			OUTPUT_VARIABLE SDK
			OUTPUT_STRIP_TRAILING_WHITESPACE
	)
endif()

if (NOT EXISTS ${SDK})
	message(FATAL_ERROR "SDK Path not found; set ENV value PLAYDATE_SDK_PATH")
	return()
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

# Game Name Customization
set(PLAYDATE_GAME_NAME PokeDate)
set(PLAYDATE_GAME_DEVICE PokeDate_DEVICE)

project(${PLAYDATE_GAME_NAME} C CXX ASM)

if (TOOLCHAIN STREQUAL "armgcc")
	add_executable(${PLAYDATE_GAME_DEVICE} ${SDK}/C_API/buildsupport/setup.c
		src/core/audio.cpp
		src/core/blitter.cpp
		src/core/control.cpp
		src/core/eeprom.cpp
		src/core/gpio.cpp
		src/core/input.cpp
		src/core/irq.cpp
		src/core/lcd.cpp
		src/core/machine.cpp
		src/core/operations.cpp
		src/core/rtc.cpp
		src/core/tim256.cpp
		src/core/timers.cpp
		src/main.cpp
	)
else()
	add_library(${PLAYDATE_GAME_NAME} SHARED 
		src/core/audio.cpp
		src/core/blitter.cpp
		src/core/control.cpp
		src/core/eeprom.cpp
		src/core/gpio.cpp
		src/core/input.cpp
		src/core/irq.cpp
		src/core/lcd.cpp
		src/core/machine.cpp
		src/core/operations.cpp
		src/core/rtc.cpp
		src/core/tim256.cpp
		src/core/timers.cpp
		src/main.cpp
	)
endif()

include_directories("src/include")
include(${SDK}/C_API/buildsupport/playdate_game.cmake)
