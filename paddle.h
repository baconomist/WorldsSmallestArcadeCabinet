#pragma once

#include "U8g2lib.h"
#include "input.h"

class Paddle
{
public:
	static const int WIDTH = 2;
	static const int LENGTH = 10;

	int x = 0;
	int y = 0;

	Paddle();

	void draw(U8G2 display);

	void update();

	virtual bool up_button_pressed();
	virtual bool down_button_pressed();
};

class LeftPaddle : public Paddle
{
public:
	LeftPaddle();
	bool up_button_pressed();
	bool down_button_pressed();
};

class RightPaddle : public Paddle
{
public:
	RightPaddle();
	bool up_button_pressed();
	bool down_button_pressed();
};
