#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"


KEYBOARD::KEYBOARD(WINDOW& win, SNAKE* snak)
{
	CurWin = &win.CurWin;
	press = 0;
	snake = snak;
}
void KEYBOARD::handleKeyInput(int key, int scancode, int action, int mods)
{
	if (action == GLFW_RELEASE) {
		press = false; // Сброс флага при отпускании клавиши
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		if (*CurWin == 5)*CurWin = 6;
		else *CurWin = 5;
		while (*CurWin == 6) {
			glfwPollEvents();
		}
	}
	else if (*CurWin == 5 && action == GLFW_PRESS && !press)
	{
		if (key == GLFW_KEY_S)
		{
			if (snake->Head->side != 'D' && snake->Head->side != 'U')
			{
				snake->Head->side = 'D';
				snake->Head->turn = true;
				press = true;
			}
		}
		else if (key == GLFW_KEY_W)
		{
			if (snake->Head->side != 'D' && snake->Head->side != 'U')
			{
				snake->Head->side = 'U';
				snake->Head->turn = true;
				press = true;
			}
		}
		else if (key == GLFW_KEY_D)
		{
			if (snake->Head->side != 'L' && snake->Head->side != 'R')
			{
				snake->Head->side = 'R';
				snake->Head->turn = true;
				press = true;
			}
		}
		else if (key == GLFW_KEY_A)
		{
			if (snake->Head->side != 'L' && snake->Head->side != 'R')
			{
				snake->Head->side = 'L';
				snake->Head->turn = true;
				press = true;
			}
		}
	}
}
void KEYBOARD::menu(GLFWwindow* window, int key, int scancode, int action, int mods) {}

