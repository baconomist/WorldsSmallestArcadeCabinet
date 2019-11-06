// 
// 
// 

#include "globals.h"

#include "ball.h"

const int RADIUS = 3;

Ball::Ball() {
	x = 0;
	y = 0;
}

void Ball::start()
{
	setVelocity(5, 5);
}

char hg[10];
void Ball::draw(U8G2 display)
{
	sprintf(hg, "%d, %d", x, y);
	Serial.println(hg);

	display.drawFilledEllipse(x, y, RADIUS, RADIUS*2, U8G2_DRAW_ALL);

	update();
}

void Ball::update()
{
	x += (int)(vel_x * pongGame.deltaTime);
	y += (int)(vel_y * pongGame.deltaTime);
}

void Ball::handleBounds() 
{
	if (x < 0)
		x = 0;
	else if (x > pongGame.getWidth())
		x = pongGame.getWidth();

	if (y < 0)
		y = 0;
	else if (y > pongGame.getHeight())
		y = pongGame.getHeight();

}

void Ball::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Ball::setVelocity(float vel_x, float vel_y)
{
	this->vel_x = vel_x;
	this->vel_y = vel_y;
}

