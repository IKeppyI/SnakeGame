#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
BANANA::BANANA(MAP* map) :FOOD(map) {
	map->change(x, y, Bonus);
}
void BANANA::make(MAP* map) {
	posgen(map);
	map->change(x, y, Bonus);
}
void BANANA::Draw()
{
	glBegin(GL_POLYGON);
	glColor3f(0.867, 0.687, 0.035);
	glVertex2f(x + 0.1, y + 0.2);
	glVertex2f(x + 0.5, y + 0.2);
	glVertex2f(x + 0.7, y + 0.3);
	glVertex2f(x + 0.9, y + 0.5);
	glVertex2f(x + 1, y + 0.7);
	glVertex2f(x + 1, y + 0.9);
	glVertex2f(x + 0.8, y + 0.9);
	glVertex2f(x + 0.7, y + 0.7);
	glVertex2f(x + 0.5, y + 0.5);
	glVertex2f(x + 0.3, y + 0.4);
	glVertex2f(x + 0.1, y + 0.3);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.328, 0.262, 0.012);
	glVertex2f(x + 0.1, y + 0.2);
	glVertex2f(x + 0.1, y + 0.3);
	glVertex2f(x + 0.2, y + 0.3);
	glVertex2f(x + 0.2, y + 0.2);
	glVertex2f(x + 0.8, y + 1);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x + 1, y + 0.9);
	glVertex2f(x + 0.8, y + 0.9);
	glEnd();

}
void BANANA::get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)
{
	if (state->scoreup())snake.SpeedChng(0, 1.5);
	snake.Grow(map);
}