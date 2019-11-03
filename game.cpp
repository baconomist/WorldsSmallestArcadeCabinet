// 
// 
// 

#include "game.h"
#include "ball.h"

Game::Game(U8G2 display)
{
	this->display = display;

	pongBall = new Ball();
	pongBall->setPosition(10, 10);
	pongBall->start();
}

int Game::getWidth() { return display.getWidth(); }
int Game::getHeight() { return display.getHeight(); }

void Game::start()
{
	display.begin();
	Serial.begin(9600);
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
	pongBall->draw(display);
	display.sendBuffer();
}

