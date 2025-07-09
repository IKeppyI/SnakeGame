#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"


void DEATH_UI::ChooseInsult(char* text)
{

	char random;
	srand(time(NULL));
	random = rand() % 11;
	strcpy(text, insults[random]);
}

void  DEATH_UI :: draw(GAMESTATE* state, WINDOW& death) {
		char buffer[38];
		int s, h;
		state->Score(&s, &h);
		_itoa(s, &total[21], 10);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		glViewport(0, 0, 400, 300);
		glLoadIdentity();
		glScalef(0.03, -0.03, 1);
		glClearColor(0.164, 0.609, 0.394, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		print_string(-28, -25, over, 0.836, 0.535, 0.387);
		glScalef(0.7, 0.7, 1);
		print_string(-41, 30, leave, 0.215, 0.394, 0.5);
		glScalef(0.5, 0.5, 1);
		print_string(-80, -30, total, 0.836, 0.535, 0.387);
		ChooseInsult(buffer);
		glScalef(1.3, 1.3, 1);
		print_string(-61, 5, buffer, 0, 0, 0);
		glfwSwapBuffers(death.WIN());

	}