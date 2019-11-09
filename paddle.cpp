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
	if (pongGame.input.GetButtonDown(pongGame.input.buttons.LEFT_BOTTOM)) 
	{
		y -= 1;
	}
	else if (pongGame.input.GetButtonDown(pongGame.input.buttons.LEFT_TOP)) 
	{
		y += 1;
	}

	//Serial.println(pongGame.input.GetButtonDown(pongGame.input.buttons.LEFT_BOTTOM));
}
