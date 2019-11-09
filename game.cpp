// 
// 
// 

#include "game.h"
#include "ball.h"
#include "input.h"

Game::Game(U8G2 display, Input input) : pongBall(), paddle()
{
	this->display = display;
	this->input = input;

	pongBall.start();
}

int Game::getWidth() { return display.getWidth(); }
int Game::getHeight() { return display.getHeight(); }

void Game::start()
{
	display.begin();
}

void Game::gameLoop()
{
	frame_t_start = millis();
	
	draw();
	
	deltaTime = (millis() - frame_t_start) / 1000.0f;
}

void Game::draw()
{
	display.clearBuffer();
	// Draw stuff to the buffer here
	pongBall.draw(display);
	paddle.draw(display);
	display.sendBuffer();
}

