#pragma once

#include "U8g2lib.h"
#include "input.h"

class Paddle
{
public:
	static const int WIDTH = 2;
	static const int LENGTH = 20;

	int x = 0;
	int y = 0;

	Paddle();

	void draw(U8G2 display);

	void update();
};

