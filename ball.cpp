// 
// 
// 

#include "globals.h"

#include "ball.h"

const float MIN_VEL = 1;
const float MAX_VEL = 100;

int clamp(int x, int min, int max) 
{
	return ((x < min ? min : x) == min ? min : ((x > max) ? max : x));
}

int sign(int x) 
{
	return (x > 0 ? 1 : -1);
}

int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}

const int RADIUS = 2;

Ball::Ball() {
	x = pongGame.getWidth() / 2;
	y = pongGame.getHeight() / 2;
}

void Ball::start()
{
	float x_velocity = random(1, 20) / 10.0f * (random(10, 100) > 50 ? 1 : -1);
	setVelocity(x_velocity, x_velocity * random(50, 100)/100.0f);
}

void Ball::draw(U8G2 display)
{
	display.drawFilledEllipse(x, y, RADIUS, RADIUS, U8G2_DRAW_ALL);

	update();
}

void Ball::update()
{
	int actual_vel_x = round((vel_x * pongGame.deltaTime * 100));
	int actual_vel_y = round((vel_y * pongGame.deltaTime * 100));
	x += actual_vel_x;
	y += actual_vel_y;
	Serial.println(actual_vel_x);

	handleBounce();
}

void Ball::handleBounce()
{
	int next_x = x + (int)(vel_x * pongGame.deltaTime * 100);
	int next_y = y + (int)(vel_y * pongGame.deltaTime * 100);

	if ((next_x - RADIUS * 2 < 0) || (next_x + RADIUS * 2 > pongGame.getWidth()))
	{
		vel_x = -vel_x;
		onBounce();
	}
	if ((next_y - RADIUS * 2 < 0) || (next_y + RADIUS * 2 > pongGame.getHeight()))
	{
		vel_y = -vel_y;
		onBounce();
	}
}

void Ball::onBounce()
{
	if ((abs(pongGame.leftPaddle.y - y) > Paddle::LENGTH && (x - RADIUS * 2 < 0)) || (abs(pongGame.rightPaddle.y - y) > Paddle::LENGTH && (x + RADIUS * 2 > pongGame.getWidth())))
		Serial.println("Game Over!");
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

