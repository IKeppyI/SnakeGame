#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
MUSHROOM::MUSHROOM(MAP* map) :FOOD(map) {
	map->change(x, y, Bonus);
}
void MUSHROOM::make(MAP* map) {
	posgen(map);
	map->change(x, y, Bonus);
}
void MUSHROOM::Draw()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(x, y + 0.5);
	glVertex2f(x, y + 0.9);
	glVertex2f(x + 0.2, y + 1);
	glVertex2f(x + 0.8, y + 1);
	glVertex2f(x + 1, y + 0.9);
	glVertex2f(x + 1, y + 0.5);
	glVertex2f(x + 0.8, y + 0.4);
	glVertex2f(x + 0.2, y + 0.4);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.918, 0.773, 0.414);
	glVertex2f(x + 0.4, y);
	glVertex2f(x + 0.6, y);
	glVertex2f(x + 0.7, y + 0.1);
	glVertex2f(x + 0.7, y + 0.2);
	glVertex2f(x + 0.6, y + 0.3);
	glVertex2f(x + 0.6, y + 0.4);
	glVertex2f(x + 0.4, y + 0.4);
	glVertex2f(x + 0.4, y + 0.3);
	glVertex2f(x + 0.3, y + 0.2);
	glVertex2f(x + 0.3, y + 0.1);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(x + 0.3, y + 0.4);
	glVertex2f(x + 0.4, y + 0.4);
	glVertex2f(x + 0.4, y + 0.5);
	glVertex2f(x + 0.3, y + 0.5);
	glVertex2f(x + 0.1, y + 0.6);
	glVertex2f(x + 0.2, y + 0.6);
	glVertex2f(x + 0.2, y + 0.7);
	glVertex2f(x + 0.1, y + 0.7);
	glVertex2f(x + 0.2, y + 0.8);
	glVertex2f(x + 0.3, y + 0.8);
	glVertex2f(x + 0.3, y + 0.9);
	glVertex2f(x + 0.2, y + 0.9);
	glVertex2f(x + 0.5, y + 0.6);
	glVertex2f(x + 0.6, y + 0.6);
	glVertex2f(x + 0.6, y + 0.7);
	glVertex2f(x + 0.5, y + 0.7);
	glVertex2f(x + 0.7, y + 0.9);
	glVertex2f(x + 0.8, y + 0.9);
	glVertex2f(x + 0.8, y + 1);
	glVertex2f(x + 0.7, y + 1);
	glVertex2f(x + 0.7, y + 0.7);
	glVertex2f(x + 0.8, y + 0.7);
	glVertex2f(x + 0.8, y + 0.8);
	glVertex2f(x + 0.7, y + 0.8);
	glVertex2f(x + 0.8, y + 0.5);
	glVertex2f(x + 0.9, y + 0.5);
	glVertex2f(x + 0.9, y + 0.6);
	glVertex2f(x + 0.8, y + 0.6);
	glEnd();

}
void MUSHROOM::get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)
{
	snake.SpeedChng(1, 1.2);
}