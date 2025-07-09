#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
FOOD::FOOD(MAP* map)
{
	posgen(map);
}
void FOOD::posgen(MAP* map)
{
	srand(time(NULL));
	do
	{
		x = rand() % map->Size();
		y = rand() % map->Size();
	} while (map->type(x, y));
}
void FOOD::pos(short* x1, short* y1)
{
	*x1 = x;
	*y1 = y;
}
void FOOD::del(MAP* map)
{
	map->change(x, y, Empty);
	x = -1;
	y = -1;
}
