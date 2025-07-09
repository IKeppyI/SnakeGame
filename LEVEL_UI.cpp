#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
LEVEL_UI::LEVEL_UI(int lvl):level(lvl) {}
void LEVEL_UI::draw(GAMESTATE* state) {
	int s, h;
	bool x2, b;
	state->Score(&s, &h);
	state->Flags(&x2, &b);
	glViewport(0, 0, 1000, 1000);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glScalef(0.006, -0.006, 1);
	_itoa(h, &hscore[12], 10);
	_itoa(s, &score[9], 10);
	strcat(hscore, score);
	print_string(-165, -130, hscore, 0, 0, 0);
	print_string(20, -130, lvlstr[level-1], 0, 0, 0);
	glScalef(1.5, 1.5, 1);
	print_string(20, -70, back, 0.215, 0.394, 0.5);
	if (x2)
	{
		glScalef(0.7, 0.7, 1);
		print_string(-70, -102, bonus, 1, 0, 0);
	}
}