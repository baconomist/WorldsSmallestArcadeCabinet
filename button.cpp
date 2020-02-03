#include "U8g2lib.h"
#include "button.h"

Button::Button()
{
}


Button::~Button()
{
}

void Button::draw(U8G2 display)
{
	if (active)
	{
		display.drawFrame(x - 3, y - 10, 30, 15);
	}

	display.drawStr(x, y, text);
}
