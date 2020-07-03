// 
// 
// 


#include "game.h"
#include "ball.h"
#include "input.h"

#include "sound_manager.h"

const bool round_timer_enabled = false;
float menu_accumilator = 0;
bool draw_pre_round_timer = true;
bool set_delta_time_zero = false;

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
	display.setFont(u8g2_font_5x7_mf);

	showSplashScreen();
}

void Game::nextRound() 
{
	// Reset ball
	pongBall.reset();
	pongBall.start();
	
	// Enable pre-round timer
	draw_pre_round_timer = true;
}

char dtPrintBuffer[50];
float log_timer = 0;
void Game::gameLoop()
{
	frame_t_start = millis();

	draw();

	deltaTime = (millis() - frame_t_start) / 1000.0f;

	if (set_delta_time_zero)
	{
		deltaTime = 0;
		set_delta_time_zero = false;
	}

	if (millis() - log_timer > 1000) {
		sprintf(dtPrintBuffer, "Delta Time: %dms, FPS: %d", (int)(deltaTime * 1000), (int)(1 / deltaTime));
		Serial.println(dtPrintBuffer);
		log_timer = millis();
	}
}

void Game::drawMainMenu()
{
	display.drawFrame(0, 0, getWidth(), getHeight());

	if (menu_accumilator <= 0.5f)
	{
		display.drawStr(getWidth() / 4, getHeight() / 2 - 5, "Press");
		display.drawStr(getWidth() / 4, getHeight() / 2 + 5, "2 Play");
	}
	
	if (menu_accumilator > 1)
		menu_accumilator = 0;
	else
		menu_accumilator += deltaTime;

	if (input.GetButtonDown(input.buttons.LEFT_BOTTOM) || input.GetButtonDown(input.buttons.LEFT_TOP) || input.GetButtonDown(input.buttons.RIGHT_BOTTOM) || input.GetButtonDown(input.buttons.RIGHT_TOP))
		in_main_menu = false;
}

void Game::drawGameOverScreen() 
{
	display.drawFrame(0, 0, getWidth(), getHeight());

	if (menu_accumilator <= 0.5f)
	{
		display.drawStr(getWidth() / 6, getHeight() / 2 - 5, (score.left_player_score >= 11 ? "L-Player" : "R-Player"));
		display.drawStr(getWidth() / 6 + 10, getHeight() / 2 + 5, "Won!");
		SoundManager::playHighBeep();
	}
	else if (menu_accumilator <= 1.0f) {}
	else if (menu_accumilator <= 1.5f) 
	{
		display.drawStr(getWidth() / 8, getHeight() / 2 - 5, "Game Over");
		display.drawStr(getWidth() / 8, getHeight() / 2 + 5, "PressReset");
	}

	if (menu_accumilator > 2.0f)
		menu_accumilator = 0;
	else
		menu_accumilator += deltaTime;

	if (input.GetButtonDown(input.buttons.LEFT_BOTTOM) || input.GetButtonDown(input.buttons.LEFT_TOP) || input.GetButtonDown(input.buttons.RIGHT_BOTTOM) || input.GetButtonDown(input.buttons.RIGHT_TOP))
	{
		score.left_player_score = 0;
		score.right_player_score = 0;
		game_over = false;
		nextRound();
	}
}

void Game::drawGame() 
{
	pongBall.draw(display);
	leftPaddle.draw(display);
	rightPaddle.draw(display);
	score.draw(display);

	draw_centerline(this);
}

void Game::updateGame()
{
	pongBall.update();
	leftPaddle.update();
	rightPaddle.update();
}

void Game::showSplashScreen() 
{
	menu_accumilator = 0;
	
	const int LEN_WORDS = 14;
	char* words[LEN_WORDS] = {"GET", "READY", "FOR", "THE", "WORLD's", "SMALLEST", "GAME", "OF", "PONG", "BY", "NATHAN", "GREEN", "AND", "LUCAS"};
	for (int i = 0; i < LEN_WORDS; i++)
	{
		display.clearBuffer();
		display.drawStr(getWidth() / 6, getHeight() / 2, words[i]);
		display.sendBuffer();
		delay(500);
	}

	int x = -50;
	while (x < 10) 
	{
		display.clearBuffer();
		display.drawStr(x, getHeight() / 2, "BOROWIECKI");
		display.sendBuffer();
		x++;
		delay(10);
	}
	delay(100);
	
	menu_accumilator = 0;
}

void Game::draw()
{
	if(score.left_player_score >= 11 || score.right_player_score >= 11)
		game_over = true;

	display.clearBuffer();

	// Draw stuff to the buffer here
	if (in_main_menu)
		drawMainMenu();
	else if (game_over)
		drawGameOverScreen();
	else
	{
		if (draw_pre_round_timer)
		{		
			// Pre-round timer
			for (int i = 3; i > 0; i--)
			{
				if (round_timer_enabled)
				{
					char buff[10];
					sprintf(buff, "%d", i);

					display.clearBuffer();

					drawGame();

					display.setFont(u8g2_font_10x20_mf);
					display.drawStr(getWidth() / 2.0f - 5, getHeight() / 2.0f, buff);

					display.sendBuffer();
				}
				
				SoundManager::playLowBeep();
				
				delay(500);
			}

			// Reset Font
			display.setFont(u8g2_font_5x7_mf);
			
			draw_pre_round_timer = false;
			// Prevent updates until frame after round timer
			set_delta_time_zero = true;

			SoundManager::playHighBeep();
		}
		else
		{
			display.setFont(u8g2_font_5x7_mf);
			updateGame();
			drawGame();
		}
	}
	
	display.sendBuffer();
}

