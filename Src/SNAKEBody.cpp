#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
SNAKEBody::SNAKEBody(short x1, short y1, const char side1, SNAKEBody* back1) :x(x1), y(y1), side(side1), turn(false), back(back1) {}
void SNAKEBody::pos(short* x1, short* y1) { (*x1) = x; (*y1) = y; }
void SNAKEBody::direct(char* side1, bool* turn1) { (*side1) = side; (*turn1) = turn; }
void SNAKEBody::body(char* side1, bool* turn1) { (*side1) = side; (*turn1) = turn; }
void SNAKEBody::change(short x1, short y1, bool turn1, const char side1, SNAKEBody* back1)
{
	if (x1 != -1)x = x1;
	if (y1 != -1)y = y1;
	if (side1 != -1)side = side1;
	if (turn1 != -1)turn = turn1;
	if (back1 != 0)back = back1;
}
void SNAKEBody::clr() { back = nullptr; };
SNAKEBody* SNAKEBody::Back() { return back; }
void SNAKEBody::Draw(SNAKEBody* prev) {
	if (turn && prev != nullptr)
	{
		if (side == 'U' && prev->side == 'L' || side == 'R' && prev->side == 'D')
		{
			glBegin(GL_POLYGON);
			glColor3f(0.172, 0.668, 0.371);
			glVertex2f(x + 1, y + 0.2);
			glVertex2f(x + 0.5, y + 0.2);
			glVertex2f(x + 0.2, y + 0.5);
			glVertex2f(x + 0.2, y + 1);
			glVertex2f(x + 0.8, y + 1);
			glVertex2f(x + 0.8, y + 0.9);
			glVertex2f(x + 0.9, y + 0.8);
			glVertex2f(x + 1, y + 0.8);
			glEnd();
			glColor3f(1, 1, 0);
			glBegin(GL_QUADS);
			glVertex2f(x + 1, y + 0.3);
			glVertex2f(x + 0.8, y + 0.3);
			glVertex2f(x + 0.8, y + 0.5);
			glVertex2f(x + 1, y + 0.5);
			glVertex2f(x + 0.8, y + 0.5);
			glVertex2f(x + 0.6, y + 0.5);
			glVertex2f(x + 0.6, y + 0.7);
			glVertex2f(x + 0.8, y + 0.7);
			glVertex2f(x + 0.5, y + 0.6);
			glVertex2f(x + 0.3, y + 0.6);
			glVertex2f(x + 0.3, y + 0.8);
			glVertex2f(x + 0.5, y + 0.8);
			glVertex2f(x + 0.5, y + 0.8);
			glVertex2f(x + 0.5, y + 1);
			glVertex2f(x + 0.7, y + 1);
			glVertex2f(x + 0.7, y + 0.8);
			glEnd();

		}
		else if (side == 'R' && prev->side == 'U' || side == 'D' && prev->side == 'L')
		{
			glBegin(GL_POLYGON);
			glColor3f(0.172, 0.668, 0.371);
			glVertex2f(x + 0.2, y);
			glVertex2f(x + 0.2, y + 0.5);
			glVertex2f(x + 0.5, y + 0.8);
			glVertex2f(x + 1, y + 0.8);
			glVertex2f(x + 1, y + 0.2);
			glVertex2f(x + 0.9, y + 0.2);
			glVertex2f(x + 0.8, y + 0.1);
			glVertex2f(x + 0.8, y);
			glEnd();
			glColor3f(1, 1, 0);
			glBegin(GL_QUADS);
			glVertex2f(x + 0.3, y);
			glVertex2f(x + 0.3, y + 0.2);
			glVertex2f(x + 0.5, y + 0.2);
			glVertex2f(x + 0.5, y);
			glVertex2f(x + 0.5, y + 0.2);
			glVertex2f(x + 0.5, y + 0.4);
			glVertex2f(x + 0.7, y + 0.4);
			glVertex2f(x + 0.7, y + 0.2);
			glVertex2f(x + 0.6, y + 0.5);
			glVertex2f(x + 0.6, y + 0.7);
			glVertex2f(x + 0.8, y + 0.7);
			glVertex2f(x + 0.8, y + 0.5);
			glVertex2f(x + 0.8, y + 0.5);
			glVertex2f(x + 0.8, y + 0.3);
			glVertex2f(x + 1, y + 0.3);
			glVertex2f(x + 1, y + 0.5);
			glEnd();
		}
		else if (side == 'L' && prev->side == 'U' || side == 'D' && prev->side == 'R')
		{
			glBegin(GL_POLYGON);
			glColor3f(0.172, 0.668, 0.371);
			glVertex2f(x, y + 0.8);
			glVertex2f(x + 0.5, y + 0.8);
			glVertex2f(x + 0.8, y + 0.5);
			glVertex2f(x + 0.8, y);
			glVertex2f(x + 0.2, y);
			glVertex2f(x + 0.2, y + 0.1);
			glVertex2f(x + 0.1, y + 0.2);
			glVertex2f(x, y + 0.2);
			glEnd();
			glColor3f(1, 1, 0);
			glBegin(GL_QUADS);
			glVertex2f(x + 0.3, y);
			glVertex2f(x + 0.3, y + 0.2);
			glVertex2f(x + 0.5, y + 0.2);
			glVertex2f(x + 0.5, y);
			glVertex2f(x + 0.5, y + 0.2);
			glVertex2f(x + 0.5, y + 0.4);
			glVertex2f(x + 0.7, y + 0.4);
			glVertex2f(x + 0.7, y + 0.2);
			glVertex2f(x + 0.2, y + 0.3);
			glVertex2f(x + 0.2, y + 0.5);
			glVertex2f(x + 0.4, y + 0.5);
			glVertex2f(x + 0.4, y + 0.3);
			glVertex2f(x, y + 0.5);
			glVertex2f(x, y + 0.7);
			glVertex2f(x + 0.2, y + 0.7);
			glVertex2f(x + 0.2, y + 0.5);
			glEnd();
		}
		else if (side == 'U' && prev->side == 'R' || side == 'L' && prev->side == 'D')
		{
			glBegin(GL_POLYGON);
			glColor3f(0.172, 0.668, 0.371);
			glVertex2f(x, y + 0.2);
			glVertex2f(x + 0.5, y + 0.2);
			glVertex2f(x + 0.8, y + 0.5);
			glVertex2f(x + 0.8, y + 1);
			glVertex2f(x + 0.2, y + 1);
			glVertex2f(x + 0.2, y + 0.9);
			glVertex2f(x + 0.1, y + 0.8);
			glVertex2f(x, y + 0.8);
			glEnd();
			glColor3f(1, 1, 0);
			glBegin(GL_QUADS);
			glVertex2f(x, y + 0.5);
			glVertex2f(x + 0.2, y + 0.5);
			glVertex2f(x + 0.2, y + 0.7);
			glVertex2f(x, y + 0.7);
			glVertex2f(x + 0.2, y + 0.3);
			glVertex2f(x + 0.4, y + 0.3);
			glVertex2f(x + 0.4, y + 0.5);
			glVertex2f(x + 0.2, y + 0.5);
			glVertex2f(x + 0.3, y + 0.6);
			glVertex2f(x + 0.5, y + 0.6);
			glVertex2f(x + 0.5, y + 0.8);
			glVertex2f(x + 0.3, y + 0.8);
			glVertex2f(x + 0.5, y + 0.8);
			glVertex2f(x + 0.7, y + 0.8);
			glVertex2f(x + 0.7, y + 1);
			glVertex2f(x + 0.5, y + 01);
			glEnd();
		}
	}
	//тело змейки
	else if (side == 'U' || side == 'D')
	{

		glBegin(GL_QUADS);
		glColor3f(0.172, 0.668, 0.371);
		glVertex2f(x + 0.2, y);
		glVertex2f(x + 0.2, y + 1);
		glVertex2f(x + 0.8, y + 1);
		glVertex2f(x + 0.8, y);
		glColor3f(1, 1, 0);
		glVertex2f(x + 0.3, y);
		glVertex2f(x + 0.5, y);
		glVertex2f(x + 0.5, y + 0.2);
		glVertex2f(x + 0.3, y + 0.2);
		glVertex2f(x + 0.3, y + 0.5);
		glVertex2f(x + 0.5, y + 0.5);
		glVertex2f(x + 0.5, y + 0.7);
		glVertex2f(x + 0.3, y + 0.7);
		glVertex2f(x + 0.5, y + 0.3);
		glVertex2f(x + 0.7, y + 0.3);
		glVertex2f(x + 0.7, y + 0.5);
		glVertex2f(x + 0.5, y + 0.5);
		glVertex2f(x + 0.5, y + 0.8);
		glVertex2f(x + 0.7, y + 0.8);
		glVertex2f(x + 0.7, y + 1);
		glVertex2f(x + 0.5, y + 1);
		glEnd();
	}
	else if (side == 'R' || side == 'L')
	{
		glBegin(GL_QUADS);
		glColor3f(0.172, 0.668, 0.371);
		glVertex2f(x, y + 0.2);
		glVertex2f(x + 1, y + 0.2);
		glVertex2f(x + 1, y + 0.8);
		glVertex2f(x, y + 0.8);
		glColor3f(1, 1, 0);
		glVertex2f(x + 1, y + 0.3);
		glVertex2f(x + 1, y + 0.5);
		glVertex2f(x + 0.8, y + 0.5);
		glVertex2f(x + 0.8, y + 0.3);
		glVertex2f(x + 0.5, y + 0.3);
		glVertex2f(x + 0.5, y + 0.5);
		glVertex2f(x + 0.3, y + 0.5);
		glVertex2f(x + 0.3, y + 0.3);
		glVertex2f(x + 0.5, y + 0.5);
		glVertex2f(x + 0.7, y + 0.5);
		glVertex2f(x + 0.7, y + 0.7);
		glVertex2f(x + 0.5, y + 0.7);
		glVertex2f(x, y + 0.5);
		glVertex2f(x + 0.2, y + 0.5);
		glVertex2f(x + 0.2, y + 0.7);
		glVertex2f(x, y + 0.7);
		glEnd();
	}
}