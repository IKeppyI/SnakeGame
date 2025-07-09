#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
GAMESTATE::GAMESTATE(int num) :score(0), Bonus(1), x2(0), foodtime(clock()), hScore(num), counter(0) {};
void GAMESTATE::timerset(int time, bool drop) { foodtime = time + clock(); if (drop)Bonus = 0; }
void GAMESTATE::setx2(bool t) { x2 = t; }
bool GAMESTATE::scoreup() {
	counter++;
	if (!x2) score += 100;
	else score += 200;
	if (score >= hScore)hScore = score;
	if (counter == 5) { counter = 0; return 1; }
	return 0;
};
void GAMESTATE::Score(int* s, int* h)
{
	*s = score;
	*h = hScore;
}
void GAMESTATE::Flags(bool* x, bool* B)
{
	*x = x2;
	*B = Bonus;
}
char GAMESTATE::checkflags()
{
	char f = 0;
	if (!(Bonus || x2))
	{
		timerset(15000, 0);
		Bonus = true;
		f = 1;
	}
	else if (Bonus)
	{
		timerset(15000, 1);
		f = 2;
	}
	else if (x2)
	{
		x2 = 0;
		timerset(15000, 0);
		f = 3;
	}
	return f;
}
bool GAMESTATE::checktime()
{
	return(clock() > foodtime);
}
