#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
LOLYPOP::LOLYPOP(MAP* map) :FOOD(map) {
	map->change(x, y, Bonus);
}
void LOLYPOP::make(MAP* map) {
	posgen(map);
	map->change(x, y, Bonus);
}
void LOLYPOP::Draw()
{

	glBegin(GL_POLYGON);
	glColor3f(0.965, 0.473, 0.145);
	glVertex2f(x + 0.5, y + 0.3);
	glVertex2f(x + 0.7, y + 0.3);
	glVertex2f(x + 0.9, y + 0.5);
	glVertex2f(x + 0.9, y + 0.7);
	glVertex2f(x + 0.7, y + 0.9);
	glVertex2f(x + 0.5, y + 0.9);
	glVertex2f(x + 0.3, y + 0.7);
	glVertex2f(x + 0.3, y + 0.5);
	glEnd();
	glColor3f(0.935, 0.373, 0.145);
	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 0.45, y + 0.85);
	glVertex2f(x + 0.45, y + 0.75);
	glVertex2f(x + 0.55, y + 0.55);
	glVertex2f(x + 0.75, y + 0.45);
	glVertex2f(x + 0.85, y + 0.45);
	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x + 0.1, y + 0.1);
	glVertex2f(x + 0.4, y + 0.4);
	glEnd();
}
void LOLYPOP::get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)
{
	state->setx2(1);
}