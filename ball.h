// ball.h

#ifndef _BALL_h
#define _BALL_h

enum ScreenSide { SCREEN_LEFT, SCREEN_RIGHT, SCREEN_TOP, SCREEN_BOTTOM };

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
	void reset();

	void draw(U8G2 display);
	void update();

	void handleBounce();
	
	void onBounce(ScreenSide screenSide);

	void setPosition(int x, int y);

	void setVelocity(float x, float y);
};

#endif

