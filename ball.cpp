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

/**
Our screen is in pixles which means we need to return
an integer value to add to our actual position hence the "actual velocity"
**/
int calculate_actual_velocity(float vel)
{
	int actual_vel = round(vel);
	return actual_vel;
}

float calculate_random_movable_velocity()
{
	float x_velocity = random(10, 20) / 10.0f * (random(1, 100) > 50 ? 1 : -1);
	x_velocity = clamp(abs(x_velocity), 1, abs(x_velocity)) * sign(x_velocity);
	return x_velocity;
}

const int RADIUS = 2;

Ball::Ball()
{
	reset();
}

void Ball::start()
{
	float x_velocity = calculate_random_movable_velocity();
	setVelocity(x_velocity, x_velocity * (random(1, 100) > 50 ? 1 : -1) * (random(1, 100) > 50 ? 0 : 1));
}

void Ball::reset()
{
	vel_x = 0;
	vel_y = 0;
	x = pongGame.getWidth() / 2;
	y = pongGame.getHeight() / 2;
}

void Ball::draw(U8G2 display)
{
	display.drawFilledEllipse(x, y, RADIUS, RADIUS, U8G2_DRAW_ALL);

	update();
}

void Ball::update()
{
	x += calculate_actual_velocity(vel_x);
	y += calculate_actual_velocity(vel_y);

	handleBounce();
}

void Ball::handleBounce()
{
	int next_x = x + calculate_actual_velocity(vel_x);
	int next_y = y + calculate_actual_velocity(vel_y);

	if ((next_x - RADIUS * 2 < 0) || (next_x + RADIUS * 2 > pongGame.getWidth()))
	{
		onBounce(((next_x - RADIUS * 2 < 0) ? SCREEN_LEFT : SCREEN_RIGHT));
	}
	if ((next_y - RADIUS * 2 < 0) || (next_y + RADIUS * 2 > pongGame.getHeight()))
	{
		onBounce(((next_y - RADIUS * 2 < 0) ? SCREEN_TOP : SCREEN_BOTTOM));
	}
}

void Ball::onBounce(ScreenSide screenSide)
{
	if (screenSide != SCREEN_TOP && screenSide != SCREEN_BOTTOM)
	{
		vel_x = -vel_x;
		vel_y = -vel_y;
		if (screenSide == SCREEN_LEFT)
			vel_y += ((pongGame.leftPaddle.up_button_pressed() ? 1 : 0) + (pongGame.leftPaddle.down_button_pressed() ? -1 : 0)) * (vel_y > 0 ? 1 : -1);
		else if (screenSide == SCREEN_RIGHT)
			vel_y += ((pongGame.rightPaddle.up_button_pressed() ? 1 : 0) + (pongGame.rightPaddle.down_button_pressed() ? -1 : 0)) * (vel_y > 0 ? 1 : -1);
		//vel_y = -vel_y + 1 * (random(0, 1) == 0 ? 1 : -1);
	}
	else
	{
		vel_y = -vel_y;
	}

	if ((y - pongGame.leftPaddle.y > Paddle::LENGTH || y < pongGame.leftPaddle.y) && screenSide == SCREEN_LEFT)
	{
		pongGame.nextRound();
		pongGame.score.right_player_score++;
	}
	else if ((y - pongGame.rightPaddle.y > Paddle::LENGTH || y < pongGame.rightPaddle.y) && screenSide == SCREEN_RIGHT)
	{
		pongGame.nextRound();
		pongGame.score.left_player_score++;
	}
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

