#include "U8g2lib.h"
#include "paddle.h"
#include "globals.h"

Paddle::Paddle()
{
}

void Paddle::draw(U8G2 display)
{
	display.drawBox(x, y, WIDTH, LENGTH);
	update();
}

void Paddle::update() 
{
	int speed = 5;
	if (down_button_pressed() && y - speed >= -LENGTH / 2)
	{
		y -= round(speed * pongGame.deltaTime * 10);
	}
	else if (up_button_pressed() && y + speed + LENGTH <= pongGame.getHeight() + LENGTH / 2)
	{
		y += round(speed * pongGame.deltaTime * 10);
	}
}

bool Paddle::down_button_pressed() { return false; }
bool Paddle::up_button_pressed() { return false; }

LeftPaddle::LeftPaddle()
{
	x = 0;
	y = 0;
}

bool LeftPaddle::down_button_pressed() 
{
	return pongGame.input.GetButtonDown(pongGame.input.buttons.LEFT_BOTTOM);
}

bool LeftPaddle::up_button_pressed()
{
	return pongGame.input.GetButtonDown(pongGame.input.buttons.LEFT_TOP);
}


RightPaddle::RightPaddle()
{
	x = pongGame.getWidth();
	y = 0;
}

bool RightPaddle::down_button_pressed()
{
	return pongGame.input.GetButtonDown(pongGame.input.buttons.RIGHT_BOTTOM);
}


bool RightPaddle::up_button_pressed()
{
	return pongGame.input.GetButtonDown(pongGame.input.buttons.RIGHT_TOP);
}
