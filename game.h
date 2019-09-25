// game.h

#ifndef _GAME_h
#define _GAME_h

#include <Adafruit_SSD1306.h>
#include "ball.h"

class Game
{
public:

	const int FPS = 30;

	Adafruit_SSD1306 display;
	Ball *pongBall;

	Game(Adafruit_SSD1306 display);

	int getWidth();
	int getHeight();

	void gameLoop();

	void draw();
};
#endif

