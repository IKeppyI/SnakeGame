#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
SNAKE::SNAKE(MAP* map, unsigned int sp, unsigned int sz) {
	size = 1;
	speed = sp;
	Head = Tail = new SNAKEBody(map->Size() / 2, map->Size() / 2, 'U', nullptr);
	while (size != sz)Grow(map);
}
void SNAKE::SpeedChng(bool UpOrDown, float dif)
{
	if (UpOrDown)speed /= dif;
	else speed *= dif;

}
void SNAKE::Grow(MAP* map)
{
	short x;
	short y;
	char side;
	bool change;
	Tail->pos(&x, &y);
	Tail->direct(&side, &change);
	if (side == 'U')
	{
		y--;
		if (y == 1) {
			y++;
			x--; change = 1;
			side = 'R';
		}

	}
	else if (side == 'D')
	{
		y++;
		if (y == map->Size() - 2) {
			y--;
			x++; change = 1;
			side = 'L';
		}
	}
	else if (side == 'R')
	{
		x--;
		if (x == 1) {
			x++;
			y++; change = 1;
			side = 'D';
		}
	}
	else if (side == 'L')
	{
		x++;
		if (x == map->Size() - 2) {
			x--;
			y--; change = 1;
			side = 'U';
		}
	}
	SNAKEBody* sNew = new SNAKEBody(x, y, side, Tail);
	Tail->change(-1, -1, change, -1, 0);
	map->change(x, y, Snake);
	Tail = sNew;
	size++;
}
bool SNAKE::Move(GAMESTATE* cur, FOOD* apple, FOOD* bonus, MAP* map)
{
	bool s = 0;
	char lvl = map->Level();
	short x, y, tempx, tempy;
	char side; bool turn;
	Head->pos(&x, &y);
	Head->direct(&side, &turn);
	int N = map->Size();
	if (side == 'U') {
		y++; if (y == N && lvl == 1)y = 0;
	}
	else if (side == 'D') {
		y--; if (y == -1 && lvl == 1)y = N - 1;
	}
	else if (side == 'R') {
		x++; if (x == N && lvl == 1) x = 0;
	}
	else if (side == 'L') {
		x--; if (x == -1 && lvl == 1)x = N - 1;
	}
	if (map->type(x, y))
	{
		if (map->type(x, y) == Food)
		{
			apple->get_effect(*this, cur, map);
			apple->del(map);
			apple->make(map);
		}
		else if (map->type(x, y) == Bonus)
		{
			bonus->get_effect(*this, cur, map);
			bonus->del(map);
			delete[]bonus;
			cur->timerset(15000, 1);
		}
		else
			s = 1;
	}
	map->change(x, y, Snake);
	Head->change(x, y, turn, -1, 0);
	Tail->pos(&tempx, &tempy);
	SNAKEBody* p = Tail;
	char side1; bool turn1;
	while (p != Head) // сдвиг на клетку
	{
		p->pos(&x, &y);
		p->direct(&side, &turn);
		if (side == 'U') {
			y++; if (y == N && lvl == 1)y = 0;
		}
		else if (side == 'D') {
			y--; if (y == -1 && lvl == 1)y = N - 1;
		}
		else if (side == 'R') {
			x++; if (x == N && lvl == 1) x = 0;
		}
		else if (side == 'L') {
			x--; if (x == -1 && lvl == 1)x = N - 1;
		}
		p->Back()->direct(&side1, &turn1);
		if (turn1)
		{
			p->Back()->change(-1, -1, false, -1, 0);
			turn = true;
			side = side1;
		}
		p->change(x, y, turn, side, 0);
		p = p->Back();
	}
	map->change(tempx, tempy, Empty);
	return s;
}
void SNAKE::Draw()
{

	short x, y;
	char side; bool turn;
	glLineWidth(1);
	Head->pos(&x, &y);
	Head->direct(&side, &turn);
	//голова змейки
	if (side == 'U')
	{
		glBegin(GL_POLYGON);
		glColor3f(0.172, 0.668, 0.371);
		glVertex2f(x + 0.2, y);
		glVertex2f(x + 0.8, y);
		glVertex2f(x + 0.9, y + 0.1);
		glVertex2f(x + 0.9, y + 0.4);
		glVertex2f(x + 0.6, y + 0.7);
		glVertex2f(x + 0.4, y + 0.7);
		glVertex2f(x + 0.1, y + 0.4);
		glVertex2f(x + 0.1, y + 0.1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.629, 0.105, 0.238);
		glVertex2f(x + 0.6, y + 0.7);
		glVertex2f(x + 0.6, y + 0.9);
		glVertex2f(x + 0.5, y + 0.8);
		glVertex2f(x + 0.4, y + 0.9);
		glVertex2f(x + 0.4, y + 0.7);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.6, y + 0.4);
		glVertex2f(x + 0.6, y + 0.2);
		glVertex2f(x + 0.9, y + 0.2);
		glVertex2f(x + 0.9, y + 0.4);
		glVertex2f(x + 0.1, y + 0.4);
		glVertex2f(x + 0.1, y + 0.2);
		glVertex2f(x + 0.4, y + 0.2);
		glVertex2f(x + 0.4, y + 0.4);
		glColor3f(0.289, 0.203, 0.027);
		glVertex2f(x + 0.1, y + 0.1);
		glVertex2f(x + 0.2, y);
		glVertex2f(x + 0.4, y);
		glVertex2f(x + 0.4, y + 0.1);
		glVertex2f(x + 0.9, y + 0.1);
		glVertex2f(x + 0.8, y);
		glVertex2f(x + 0.6, y);
		glVertex2f(x + 0.6, y + 0.1);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.4, y + 0.3);
		glVertex2f(x + 0.7, y + 0.3);
		glVertex2f(x + 0.4, y + 0.5);
		glVertex2f(x + 0.4, y + 0.6);
		glVertex2f(x + 0.6, y + 0.5);
		glVertex2f(x + 0.6, y + 0.6);
		glEnd();
	}
	else if (side == 'D')
	{
		glBegin(GL_POLYGON);
		glColor3f(0.172, 0.668, 0.371);
		glVertex2f(x + 0.2, y + 1);
		glVertex2f(x + 0.8, y + 1);
		glVertex2f(x + 0.9, y + 0.9);
		glVertex2f(x + 0.9, y + 0.6);
		glVertex2f(x + 0.6, y + 0.3);
		glVertex2f(x + 0.4, y + 0.3);
		glVertex2f(x + 0.1, y + 0.6);
		glVertex2f(x + 0.1, y + 0.9);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.629, 0.105, 0.238);
		glVertex2f(x + 0.6, y + 0.3);
		glVertex2f(x + 0.6, y + 0.1);
		glVertex2f(x + 0.5, y + 0.2);
		glVertex2f(x + 0.4, y + 0.1);
		glVertex2f(x + 0.4, y + 0.3);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.6, y + 0.6);
		glVertex2f(x + 0.6, y + 0.8);
		glVertex2f(x + 0.9, y + 0.8);
		glVertex2f(x + 0.9, y + 0.6);
		glVertex2f(x + 0.1, y + 0.6);
		glVertex2f(x + 0.1, y + 0.8);
		glVertex2f(x + 0.4, y + 0.8);
		glVertex2f(x + 0.4, y + 0.6);
		glColor3f(0.289, 0.203, 0.027);
		glVertex2f(x + 0.1, y + 0.9);
		glVertex2f(x + 0.2, y + 1);
		glVertex2f(x + 0.4, y + 1);
		glVertex2f(x + 0.4, y + 0.9);
		glVertex2f(x + 0.9, y + 0.9);
		glVertex2f(x + 0.8, y + 1);
		glVertex2f(x + 0.6, y + 1);
		glVertex2f(x + 0.6, y + 0.9);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.4, y + 0.7);
		glVertex2f(x + 0.7, y + 0.7);
		glVertex2f(x + 0.4, y + 0.4);
		glVertex2f(x + 0.4, y + 0.5);
		glVertex2f(x + 0.6, y + 0.4);
		glVertex2f(x + 0.6, y + 0.5);
		glEnd();
	}
	else if (side == 'R')
	{
		glBegin(GL_POLYGON);
		glColor3f(0.172, 0.668, 0.371);
		glVertex2f(x, y + 0.2);
		glVertex2f(x, y + 0.8);
		glVertex2f(x + 0.1, y + 0.9);
		glVertex2f(x + 0.4, y + 0.9);
		glVertex2f(x + 0.7, y + 0.6);
		glVertex2f(x + 0.7, y + 0.4);
		glVertex2f(x + 0.4, y + 0.1);
		glVertex2f(x + 0.1, y + 0.1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.629, 0.105, 0.238);
		glVertex2f(x + 0.7, y + 0.6);
		glVertex2f(x + 0.7, y + 0.4);
		glVertex2f(x + 0.9, y + 0.4);
		glVertex2f(x + 0.8, y + 0.5);
		glVertex2f(x + 0.9, y + 0.6);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.2, y + 0.1);
		glVertex2f(x + 0.2, y + 0.4);
		glVertex2f(x + 0.4, y + 0.4);
		glVertex2f(x + 0.4, y + 0.1);
		glVertex2f(x + 0.2, y + 0.6);
		glVertex2f(x + 0.2, y + 0.9);
		glVertex2f(x + 0.4, y + 0.9);
		glVertex2f(x + 0.4, y + 0.6);
		glColor3f(0.289, 0.203, 0.027);
		glVertex2f(x + 0.1, y + 0.1);
		glVertex2f(x, y + 0.2);
		glVertex2f(x, y + 0.4);
		glVertex2f(x + 0.1, y + 0.4);
		glVertex2f(x + 0.1, y + 0.9);
		glVertex2f(x, y + 0.8);
		glVertex2f(x, y + 0.6);
		glVertex2f(x + 0.1, y + 0.6);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.3, y + 0.4);
		glVertex2f(x + 0.3, y + 0.7);
		glVertex2f(x + 0.5, y + 0.4);
		glVertex2f(x + 0.6, y + 0.4);
		glVertex2f(x + 0.5, y + 0.6);
		glVertex2f(x + 0.6, y + 0.6);
		glEnd();
	}
	else if (side == 'L')
	{
		glBegin(GL_POLYGON);
		glColor3f(0.172, 0.668, 0.371);
		glVertex2f(x + 1, y + 0.8);
		glVertex2f(x + 1, y + 0.2);
		glVertex2f(x + 0.9, y + 0.1);
		glVertex2f(x + 0.6, y + 0.1);
		glVertex2f(x + 0.3, y + 0.4);
		glVertex2f(x + 0.3, y + 0.6);
		glVertex2f(x + 0.6, y + 0.9);
		glVertex2f(x + 0.9, y + 0.9);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.629, 0.105, 0.238);
		glVertex2f(x + 0.3, y + 0.6);
		glVertex2f(x + 0.3, y + 0.4);
		glVertex2f(x + 0.1, y + 0.4);
		glVertex2f(x + 0.2, y + 0.5);
		glVertex2f(x + 0.1, y + 0.6);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.8, y + 0.1);
		glVertex2f(x + 0.8, y + 0.4);
		glVertex2f(x + 0.6, y + 0.4);
		glVertex2f(x + 0.6, y + 0.1);
		glVertex2f(x + 0.8, y + 0.6);
		glVertex2f(x + 0.8, y + 0.9);
		glVertex2f(x + 0.6, y + 0.9);
		glVertex2f(x + 0.6, y + 0.6);
		glColor3f(0.289, 0.203, 0.027);
		glVertex2f(x + 0.9, y + 0.1);
		glVertex2f(x + 1, y + 0.2);
		glVertex2f(x + 1, y + 0.4);
		glVertex2f(x + 0.9, y + 0.4);
		glVertex2f(x + 0.9, y + 0.9);
		glVertex2f(x + 1, y + 0.8);
		glVertex2f(x + 1, y + 0.6);
		glVertex2f(x + 0.9, y + 0.6);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2f(x + 0.7, y + 0.4);
		glVertex2f(x + 0.7, y + 0.7);
		glVertex2f(x + 0.5, y + 0.4);
		glVertex2f(x + 0.4, y + 0.4);
		glVertex2f(x + 0.5, y + 0.6);
		glVertex2f(x + 0.4, y + 0.6);
		glEnd();
	}
	SNAKEBody* p = Tail;
	SNAKEBody* prev = nullptr;
	while (p != Head)
	{
		p->Draw(prev);
		prev = p;
		p = p->Back();
	}
}
void SNAKE::Decrease(short num, MAP* map) {
	SNAKEBody* p;
	short x, y;
	while (num)
	{
		if (Tail->Back())
		{
			p = Tail->Back();
			Tail->pos(&x, &y);
			map->change(x, y, Empty);
			delete Tail;
			Tail = p;
			num--;
			size--;
		}
		else { delete Head; break; };
	}
}
unsigned int SNAKE::Size() { return size; }
void SNAKE::wait()
{
	Sleep(speed);
}
SNAKE::~SNAKE()
{
	SNAKEBody* p = Tail;
	while (p)
	{
		p = Tail->Back();
		delete Tail;
		Tail = p;
	}
}