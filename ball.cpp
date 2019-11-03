// 
// 
// 

#include "globals.h"

#include "ball.h"

const int RADIUS = 3;

Ball::Ball() {

}

void Ball::start()
{
	setVelocity(0, 1);
}

void Ball::draw(U8G2 display)
{
	display.drawFilledEllipse(x, y, RADIUS, RADIUS*2, U8G2_DRAW_ALL);

	update();
}

void Ball::update()
{
	vel_x = 10*pongGame.deltaTime;
	vel_y = vel_x;

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

bool Ball::isInBoundsX() { return !(x + (int)vel_x > 0 && x + (int)vel_x < pongGame.getWidth()); }
bool Ball::isInBoundsY() { return !(y + (int)vel_y > 0 && y + (int)vel_y < pongGame.getHeight()); }

