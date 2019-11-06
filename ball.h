// ball.h

#ifndef _BALL_h
#define _BALL_h

extern const int RADIUS;

class Ball
{
public:
	int x;
	int y;

	float vel_x = 0.0f;
	float vel_y = 0.0f;

	Ball();

	void start();

	void draw(U8G2 display);
	void update();

	void handleBounds();

	void setPosition(int x, int y);

	void setVelocity(float x, float y);
};

#endif

