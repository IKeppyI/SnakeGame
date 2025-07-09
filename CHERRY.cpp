#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"



CHERRY::CHERRY(MAP* map) :FOOD(map) {
	map->change(x, y, Bonus);
}
void CHERRY::make(MAP* map) {
	posgen(map);
	map->change(x, y, Bonus);
}
void CHERRY::Draw()
{
	glBegin(GL_POLYGON);
	glColor3f(0.308, 0.027, 0.027);
	glVertex2f(x + 0.9, y);
	glVertex2f(x + 0.6, y);
	glVertex2f(x + 0.5, y + 0.1);
	glVertex2f(x + 0.5, y + 0.4);
	glVertex2f(x + 0.6, y + 0.5);
	glVertex2f(x + 0.9, y + 0.5);
	glVertex2f(x + 1, y + 0.4);
	glVertex2f(x + 1, y + 0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.199, 0.012, 0.012);
	glVertex2f(x + 0.4, y + 0.1);
	glVertex2f(x + 0.2, y + 0.1);
	glVertex2f(x + 0.1, y + 0.2);
	glVertex2f(x + 0.1, y + 0.4);
	glVertex2f(x + 0.2, y + 0.5);
	glVertex2f(x + 0.4, y + 0.5);
	glVertex2f(x + 0.5, y + 0.4);
	glVertex2f(x + 0.5, y + 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.043, 0.328, 0.113);
	glVertex2f(x + 0.6, y + 0.8);
	glVertex2f(x + 0.6, y + 0.9);
	glVertex2f(x + 0.7, y + 1);
	glVertex2f(x + 0.8, y + 1);
	glVertex2f(x + 0.8, y + 0.9);
	glVertex2f(x + 0.7, y + 0.8);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x + 0.6, y + 0.8);
	glVertex2f(x + 0.8, y + 1);
	glVertex2f(x + 0.7, y + 0.9);
	glVertex2f(x + 0.7, y + 1);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.469, 0.25, 0.0195);
	glVertex2f(x + 0.3, y + 0.5);
	glVertex2f(x + 0.6, y + 0.8);
	glVertex2f(x + 0.6, y + 0.8);
	glVertex2f(x + 0.7, y + 0.5);
	glEnd();

}
void CHERRY::get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)
{
	snake.Decrease(snake.Size() / 2, map);
}