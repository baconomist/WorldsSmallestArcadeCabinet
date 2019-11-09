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
	pinMode(buttons.LEFT_BOTTOM, INPUT_PULLUP);
	pinMode(buttons.LEFT_BOTTOM, INPUT_PULLUP);
	pinMode(buttons.RIGHT_BOTTOM, INPUT_PULLUP);
	pinMode(buttons.RIGHT_TOP, INPUT_PULLUP);
}

bool Input::GetButtonDown(int button)
{
	return !digitalRead(button);
}
