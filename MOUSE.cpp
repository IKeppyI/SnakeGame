#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
MOUSE::MOUSE(WINDOW& win) {
	CurWin = &win.CurWin;
}

void MOUSE::handleGMouseInput(GLFWwindow* window, int button, int action, int mods)
{

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		if ((*CurWin == 5 || *CurWin == 6) && xpos >= 590 && xpos <= 689 && ypos >= 84 && ypos <= 116)
		{
			*CurWin = 9;
		}
		else if ((*CurWin == 7) && xpos >= 28 && xpos <= 145 && ypos >= 245 && ypos <= 266)
		{
			*CurWin = 5;
		}
		else if ((*CurWin == 7) && xpos >= 255 && xpos <= 375 && ypos >= 245 && ypos <= 265)
		{
			*CurWin = 1;
		}
	}
}
void MOUSE::handleMMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		if (*CurWin == 1 && xpos >= 60 && xpos <= 550 && ypos >= 220 && ypos <= 290)
		{
			*CurWin = 4;
			LEVELCHOICE_UI win;
			win.draw(window);
			while (*CurWin == 4)
			{
				glfwPollEvents();
			}
		}
		else if (*CurWin == 1 && xpos >= 180 && xpos <= 410 && ypos >= 580 && ypos <= 650)
		{
			*CurWin = 0;
		}
		else if (*CurWin == 1 && xpos >= 180 && xpos <= 460 && ypos >= 340 && ypos <= 410)
		{
			*CurWin = 3;
			SCORE_UI win;
			win.draw(window);
			while (*CurWin == 3)
			{
				glfwPollEvents();
			}
		}
		else if (*CurWin == 1 && xpos >= 180 && xpos <= 400 && ypos >= 460 && ypos <= 530)
		{
			*CurWin = 2;
			HELP_UI win;
			win.draw(window);
			while (*CurWin == 2)
			{
				glfwPollEvents();
			}

		}
		else if ((*CurWin == 2 || *CurWin == 3 || *CurWin == 4) && xpos >= 450 && xpos <= 576 && ypos >= 11 && ypos <= 50)
		{
			MENU_UI m;
			m.draw(window);
			*CurWin = 1;
		}
		else if (*CurWin == 4 && xpos >= 180 && xpos <= 420 && ypos >= 300 && ypos <= 345)
		{
			*CurWin = 5;
		}
		else if (*CurWin == 4 && xpos >= 180 && xpos <= 420 && ypos >= 440 && ypos <= 485)
		{
			*CurWin = 6;
		}
		else if (*CurWin == 4 && xpos >= 180 && xpos <= 420 && ypos >= 580 && ypos <= 625)
		{
			*CurWin = 7;
		}
	}
}

