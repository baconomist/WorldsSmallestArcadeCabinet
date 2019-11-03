#include "graphics_interface.h"



IGraphics IGraphics::graphics_interface(U8G2 u8g2)
{
	this->screen = u8g2;
}

void IGraphics::drawBox(int x, int y, int w, int h)
{
}

