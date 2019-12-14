#pragma once
#include "U8g2lib.h"

class Score
{
public:
	int left_player_score = 0;
	int right_player_score = 0;

	void draw(U8G2 display);
};

