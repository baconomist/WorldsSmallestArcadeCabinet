// game.h

#pragma once

#include <U8g2lib.h>
#include "paddle.h"
#include "ball.h"
#include "input.h"

class Game
{
public:
	float deltaTime = 0;

	U8G2 display;
	Input input;
	Ball pongBall;
	Paddle paddle;

	Game(U8G2 display, Input input);

	int getWidth();
	int getHeight();

	void start();
	void gameLoop();
private:
	void draw();

	unsigned long frame_t_start = 0;
};

