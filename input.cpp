#include "input.h"
#include "Arduino.h"

Input::Input()
{
	
}

Input::Input(Buttons& buttons)
{
	this->buttons = buttons;
}

void Input::start() 
{
	pinMode(buttons.LEFT_BOTTOM, INPUT);
	pinMode(buttons.LEFT_TOP, INPUT);
	pinMode(buttons.RIGHT_BOTTOM, INPUT);
	pinMode(buttons.RIGHT_TOP, INPUT);
}

bool Input::GetButtonDown(int button)
{
	return !digitalRead(button);
}
