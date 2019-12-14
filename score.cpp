#include "score.h"
#include "globals.h"

char score_buff[10];
void Score::draw(U8G2 display)
{
	sprintf(score_buff, "%d", left_player_score);
	display.drawStr(16, 8, score_buff);
	sprintf(score_buff, "%d", right_player_score);
	display.drawStr(pongGame.getWidth() - 20, 8, score_buff);
}
