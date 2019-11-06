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

//U8G2_LD7032_60X32_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 21, /* data=*/ 20, /* reset=*/ 0);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A4, /* data=*/ A3, /* reset=*/ 0);

Game pongGame(u8g2);

void setup(void) {
	pongGame.start();
}

void loop(void) {
	pongGame.gameLoop();
}