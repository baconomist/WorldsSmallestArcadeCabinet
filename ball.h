// ball.h

#ifndef _BALL_h
#define _BALL_h

#include <Adafruit_SSD1306.h>

class Ball
{
public:
	const int RADIUS = 1.0f;

	int x = 0;
	int y = 0;

	float vel_x = 0.0f;
	float vel_y = 0.0f;

	Ball();

	void start();

	void draw(Adafruit_SSD1306 display);
	void update();

	void setPosition(int x, int y);

	void setVelocity(float x, float y);

private:

	bool isInBoundsX();
	bool isInBoundsY();

};

#endif

