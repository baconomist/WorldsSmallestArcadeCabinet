// 
// 
// 

#include "game.h"
#include "ball.h"
#include "input.h"

Game::Game(U8G2 display, Input input) : pongBall(), leftPaddle(), rightPaddle()
{
	this->display = display;
	this->input = input;

	pongBall.start();
}

int Game::getWidth() { return 60; }
int Game::getHeight() { return 32; }

void Game::start()
{
	Serial.println("Initializing display...");
	//while(!display.begin());
	display.begin();
	Serial.println("Display Initialized.");
}

char dtPrintBuffer[50];
void Game::gameLoop()
{
	frame_t_start = millis();
	
	draw();
	
	deltaTime = (millis() - frame_t_start) / 1000.0f;

	sprintf(dtPrintBuffer, "Delta Time: %dms, FPS: %d", (int)(deltaTime*1000), (int)(1 / deltaTime));
	Serial.println(dtPrintBuffer);
}

void Game::draw()
{
	display.clearBuffer();
	// Draw stuff to the buffer here
	pongBall.draw(display);
	leftPaddle.draw(display);
	rightPaddle.draw(display);
	display.sendBuffer();
}

