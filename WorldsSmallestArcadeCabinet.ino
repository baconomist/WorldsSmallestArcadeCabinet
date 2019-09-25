/*********
  Complete project details at https://randomnerdtutorials.com

  This is an example for our Monochrome OLEDs based on SSD1306 drivers. Pick one up today in the adafruit shop! ------> http://www.adafruit.com/category/63_98
  This example is for a 128x32 pixel display using I2C to communicate 3 pins are required to interface (two I2C and one reset).
  Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries, with contributions from the open source community. BSD license, check license.txt for more information All text above, and the splash screen below must be included in any redistribution.
*********/

#include "game.h"
#include "ball.h"
#include "test_drawing.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "globals.h"

Game* pongGame;

void setup() {
	Serial.begin(115200);

	// NEED TO CALL DISPLAY.BEGIN() before drawing
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
		Serial.println(F("SSD1306 allocation failed"));
		for (;;); // Don't proceed, loop forever
	}

	//display.display(); // Show splashscreen (also for showing the display buffer when finished drawing)
	//delay(2000); // Wait 2s

	// Clear display
	display.clearDisplay();
	display.display();

	pongGame = new Game(display);

	// Invert colors and restore display, pausing in-between
	/*display.invertDisplay(true);
	delay(1000);
	display.invertDisplay(false);
	delay(1000);*/
	pinMode(A2, INPUT);
}

void loop() {
	pongGame->gameLoop();

	Serial.println(analogRead(A2) / 1023.0f * 3.7);
	delay(50);
}
