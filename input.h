#pragma once

/*class Button 
{
public:
	int pin;
	// conversion to int (type-cast operator)
	operator int() { return pin; }
}*/

struct Buttons
{
public:
	static const int LEFT_BOTTOM = 2;
	static const int LEFT_TOP = 3;
	static const int RIGHT_BOTTOM = 4;
	static const int RIGHT_TOP = 5;
};

class Input
{
public:
	Buttons buttons;

	Input();
	Input(Buttons& buttons);

	void start();

	bool GetButtonDown(int button);
};

