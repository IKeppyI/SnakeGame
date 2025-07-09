#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
APPLE::APPLE(MAP* map) :FOOD(map) {
	map->change(x, y, Food);
}
void APPLE::make(MAP* map) {
	posgen(map);
	map->change(x, y, Food);
}
void APPLE::Draw()
{
	glLineWidth(1);
	glBegin(GL_POLYGON);
	glColor3f(0.012, 0.707, 0);
	glVertex2f(x + 0.5, y + 0.2);
	glVertex2f(x + 0.4, y + 0.1);
	glVertex2f(x + 0.2, y + 0.1);
	glVertex2f(x + 0.1, y + 0.2);
	glVertex2f(x + 0.1, y + 0.5);
	glVertex2f(x + 0.3, y + 0.7);
	glVertex2f(x + 0.7, y + 0.7);
	glVertex2f(x + 0.9, y + 0.5);
	glVertex2f(x + 0.9, y + 0.2);
	glVertex2f(x + 0.9, y + 0.2);
	glVertex2f(x + 0.8, y + 0.1);
	glVertex2f(x + 0.6, y + 0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.043, 0.328, 0.113);
	glVertex2f(x + 0.5, y + 0.7);
	glVertex2f(x + 0.6, y + 0.7);
	glVertex2f(x + 0.7, y + 0.8);
	glVertex2f(x + 0.7, y + 0.9);
	glVertex2f(x + 0.6, y + 0.9);
	glVertex2f(x + 0.5, y + 0.8);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x + 0.5, y + 0.7);
	glVertex2f(x + 0.7, y + 0.9);
	glVertex2f(x + 0.6, y + 0.8);
	glVertex2f(x + 0.7, y + 0.8);
	glVertex2f(x + 0.6, y + 0.8);
	glVertex2f(x + 0.6, y + 0.9);
	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.469, 0.25, 0.0195);
	glVertex2f(x + 0.5, y + 0.7);
	glVertex2f(x + 0.3, y + 0.9);
	glEnd();

}
void APPLE::get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)
{
	if (state->scoreup())snake.SpeedChng(1, 1.2);
	snake.Grow(map);
}