#pragma once

#include "U8g2lib.h"

class Button
{
public:
	bool active = false;

	int x, y = 0;

	char* text = "";

	Button();
	~Button();

	void draw(U8G2 display);
};

