// game.h

#pragma once

#include <U8g2lib.h>
#include "paddle.h"
#include "ball.h"
#include "input.h"
#include "score.h"

class Game
{
public:
	float deltaTime = 0;
	bool in_main_menu = true;
	bool game_over = false;

	U8G2 display;
	Input input;
	Ball pongBall;
	LeftPaddle leftPaddle;
	RightPaddle rightPaddle;
	Score score;

	Game(U8G2 display, Input input);

	int getWidth();
	int getHeight();

	void start();
	void nextRound();
	void gameLoop();

	void drawMainMenu();

	void drawGameOverScreen();

	void drawGame();
	void updateGame();

	void showSplashScreen();

private:
	void initialize_display();
	void draw();

	unsigned long frame_t_start = 0;
};

