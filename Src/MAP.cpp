#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"

MAP::MAP(unsigned int sizus,char lvl)
{
	size = sizus;
	level = lvl;
	A = (Cell**)malloc(size * sizeof(Cell*));
	for (int a = 0; a < size; a++) {
		A[a] = (Cell*)malloc(size * sizeof(Cell));
	}
	if (lvl == 1)
	{
		int a;
		int b;

		for (a = 0; a < size; a++)
			for (b = 0; b < size; b++)
				A[a][b] = Empty;
	}
	if (lvl == 2)
	{
		int a;
		int b;
		for (a = 0; a < size; a++)
			for (b = 0; b < size; b++)
			{
				if (a == 0 || a == size - 1 || b == 0 || b == size - 1)A[a][b] = Block;
				else A[a][b] = Empty;
			}

	}
	if (lvl == 3)
	{
		int a;
		int b;
		for (a = 0; a < size; a++)
			for (b = 0; b < size; b++)
			{
				if ((a >= 8 && a <= size - 9 && (b == 5 || b == size - 6)) || (b >= 5 && b <= size - 6 && (a == 3 || a == size - 4)) || (a == 0 || a == size - 1 || b == 0 || b == size - 1))A[a][b] = Block;
				else A[a][b] = Empty;
			}
	}
}
void MAP::Draw()
{
	if (level == 1)
	{
		glLoadIdentity();
		glTranslatef(-0.9, -0.9, 0);
		glScalef(1.28 / size, 1.28 / size, 1);
		glLineWidth(2);
		short x = 0, y = 0;
		for (x = 0; x < size; x += 1)
			for (y = 0; y < size; y += 1)
			{
				glBegin(GL_LINE_LOOP);
				glColor3f(0.6, 0.6, 0.6);
				glVertex2f(x, y);
				glVertex2f(x + 1, y);
				glVertex2f(x + 1, y + 1);
				glVertex2f(x, y + 1);
				glEnd();
			}
	}
	else if (level == 2)
	{
		glLoadIdentity();
		glTranslatef(-0.9, -0.9, 0);
		glScalef(1.28 / size, 1.28 / size, 1);
		glLineWidth(2);
		short x = 0, y = 0;
		for (x = 0; x < size; x += 1)
			for (y = 0; y < size; y += 1)
			{
				glBegin(GL_LINE_LOOP);
				glColor3f(0.6, 0.6, 0.6);
				glVertex2f(x, y);
				glVertex2f(x + 1, y);
				glVertex2f(x + 1, y + 1);
				glVertex2f(x, y + 1);
				glEnd();
			}
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(0, 0);
		glVertex2f(0, size);
		glVertex2f(1, size);
		glVertex2f(1, 0);
		glVertex2f(0, 0);
		glVertex2f(0, 1);
		glVertex2f(size, 1);
		glVertex2f(size, 0);
		glVertex2f(size - 1, 0);
		glVertex2f(size - 1, size);
		glVertex2f(size, size);
		glVertex2f(size, 0);
		glVertex2f(0, size);
		glVertex2f(size, size);
		glVertex2f(size, size - 1);
		glVertex2f(0, size - 1);
		glEnd();
	}
	else if (level == 3)
	{
		glLoadIdentity();
		glTranslatef(-0.9, -0.9, 0);
		glScalef(1.28 / size, 1.28 / size, 1);
		glLineWidth(2);
		short x = 0, y = 0;
		for (x = 0; x < size; x += 1)
			for (y = 0; y < size; y += 1)
			{
				glBegin(GL_LINE_LOOP);
				glColor3f(0.6, 0.6, 0.6);
				glVertex2f(x, y);
				glVertex2f(x + 1, y);
				glVertex2f(x + 1, y + 1);
				glVertex2f(x, y + 1);
				glEnd();
			}
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(8, 5);
		glVertex2f(size - 8, 5);
		glVertex2f(size - 8, 6);
		glVertex2f(8, 6);
		glVertex2f(8, size - 5);
		glVertex2f(size - 8, size - 5);
		glVertex2f(size - 8, size - 6);
		glVertex2f(8, size - 6);
		glVertex2f(3, 5);
		glVertex2f(4, 5);
		glVertex2f(4, size - 5);
		glVertex2f(3, size - 5);
		glVertex2f(size - 3, size - 5);
		glVertex2f(size - 4, size - 5);
		glVertex2f(size - 4, 5);
		glVertex2f(size - 3, 5);
		glVertex2f(0, 0);
		glVertex2f(0, size);
		glVertex2f(1, size);
		glVertex2f(1, 0);
		glVertex2f(0, 0);
		glVertex2f(0, 1);
		glVertex2f(size, 1);
		glVertex2f(size, 0);
		glVertex2f(size - 1, 0);
		glVertex2f(size - 1, size);
		glVertex2f(size, size);
		glVertex2f(size, 0);
		glVertex2f(0, size);
		glVertex2f(size, size);
		glVertex2f(size, size - 1);
		glVertex2f(0, size - 1);
		glEnd();
	}
}
short MAP::Size()
{
	return size;
}
void MAP::change(short x, short y, Cell type)
{
	A[x][y] = type;
}
Cell MAP::type(short x, short y)
{
	return A[x][y];
}
char MAP::Level() { return level; }
MAP::~MAP()
{
	for (int a = 0; a < size; a++) {
		delete A[a];
	}
	delete A;
}