// 
// 
// 

#include <Adafruit_SSD1306.h>

#include "globals.h"

#include "ball.h"

Ball::Ball() {}

void Ball::start()
{
	setVelocity(0, 1);
}

void Ball::draw(Adafruit_SSD1306 display)
{
	display.fillCircle(x, y, RADIUS, WHITE);

	update();
}

void Ball::update()
{
	if (isInBoundsY()) setVelocity(random(1, 2) * (random(1, 10) < 5 ? -1 : 1), -vel_y);

	x += (int)vel_x;
	y += (int)vel_y;
}

void Ball::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Ball::setVelocity(float x, float y)
{
	this->vel_x = x;
	this->vel_y = y;
}

bool Ball::isInBoundsX() { return !(x + (int)vel_x > 0 && x + (int)vel_x < pongGame->getWidth()); }
bool Ball::isInBoundsY() { return !(y + (int)vel_y > 0 && y + (int)vel_y < pongGame->getHeight()); }

