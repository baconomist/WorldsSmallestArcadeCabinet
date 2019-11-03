#pragma once

#include <U8g2lib.h>

class IGraphics
{
public:
	IGraphics graphics_interface(U8G2);

	U8G2 screen;

	void drawBox(int x, int y, int w, int h);
};