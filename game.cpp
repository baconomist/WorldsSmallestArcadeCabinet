// 
// 
// 


#include "game.h"
#include "ball.h"
#include "input.h"

Game::Game(U8G2 display, Input input) : pongBall(), leftPaddle(), rightPaddle(), score()
{
	this->display = display;
	this->input = input;
}

int Game::getWidth() { return 60; }
int Game::getHeight() { return 32; }

void Game::initialize_display()
{
	display.begin();
	display.setFont(u8g2_font_ncenB08_tr);
}

void Game::start()
{
	Serial.println("Initializing display...");
	initialize_display();
	Serial.println("Display Initialized.");

	pongBall.start();
}

void Game::goToNextRound() 
{
	pongBall.reset();
	pongBall.start();
}


char dtPrintBuffer[50];
float log_timer = 0;
void Game::gameLoop()
{
	frame_t_start = millis();

	draw();

	deltaTime = (millis() - frame_t_start) / 1000.0f;

	if (millis() - log_timer > 1000) {
		sprintf(dtPrintBuffer, "Delta Time: %dms, FPS: %d", (int)(deltaTime * 1000), (int)(1 / deltaTime));
		Serial.println(dtPrintBuffer);
		log_timer = millis();
	}
}

void draw_centerline(Game* game, int dash_height = 3)
{
	float x, y;
	x = game->getWidth() / 2;

	for (int i = 0; i < 5; i++) 
	{
		y = i * dash_height * 2;
		game->display.drawLine(x, y, x, y + dash_height);
	}
}

void Game::draw()
{
	display.clearBuffer();

	// Draw stuff to the buffer here
	pongBall.draw(display);
	leftPaddle.draw(display);
	rightPaddle.draw(display);
	score.draw(display);

	draw_centerline(this);

	display.sendBuffer();
}

