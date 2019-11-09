#include <Arduino.h>
#include <U8x8lib.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include "game.h"
#include "globals.h"

#include "input.h"

//U8G2_LD7032_60X32_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 21, /* data=*/ 20, /* reset=*/ 0);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A4, /* data=*/ A3, /* reset=*/ 0);

Buttons buttons = Buttons{};
Input input(buttons);
Game pongGame(u8g2, input);

void setup(void) {
	Serial.begin(9600);

	pongGame.start();
	input.start();
}

void loop(void) {
	pongGame.gameLoop();
}