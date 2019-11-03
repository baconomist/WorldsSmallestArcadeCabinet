// ball.h

#ifndef _BALL_h
#define _BALL_h

extern const int RADIUS;

class Ball
{
public:
	int x = 0;
	int y = 0;

	float vel_x = 0.0f;
	float vel_y = 0.0f;

	Ball();

	void start();

	void draw(U8G2 display);
	void update();

	void setPosition(int x, int y);

	void setVelocity(float x, float y);

private:

	bool isInBoundsX();
	bool isInBoundsY();

};

#endif

