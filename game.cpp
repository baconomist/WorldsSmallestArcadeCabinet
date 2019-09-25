// 
// 
// 

#include <Adafruit_SSD1306.h>

#include "game.h"
#include "ball.h"

Game::Game(Adafruit_SSD1306 display)
{
	this->display = display;

	pongBall = new Ball();
	pongBall->setPosition(10, 10);
	pongBall->start();
}

int Game::getWidth() { return display.width(); }
int Game::getHeight() { return display.height(); }

void Game::gameLoop()
{
	draw();
}

void Game::draw()
{
	display.clearDisplay();
	// Draw stuff to the buffer here
	pongBall->draw(display);
	display.display();

	// Keep a constant refresh rate
	delay((1.0f / FPS) * 1000);
}


