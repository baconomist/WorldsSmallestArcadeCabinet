// game.h

#ifndef _GAME_h
#define _GAME_h

#include <U8g2lib.h>
#include "ball.h"

class Game
{
public:
	float deltaTime = 0;

	U8G2 display;
	Ball* pongBall;

	Game(U8G2 display);

	int getWidth();
	int getHeight();

	void start();
	void gameLoop();
private:
	void draw();

	unsigned long frame_t_start = 0;
};
#endif

