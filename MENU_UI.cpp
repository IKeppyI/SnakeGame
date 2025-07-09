#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"


void MENU_UI::draw(GLFWwindow* window)
{
	glViewport(-140, -220, 1000, 1000);
	glLoadIdentity();
	glScalef(0.02, -0.02, 1);
	glClearColor(0.164, 0.609, 0.394, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	print_string(-30, -20, menu, 0.215, 0.394, 0.5);
	glScalef(1.3, 1.3, 1.3);
	print_string(-21, -30, gamename, 0.757, 0.898, 0.402);
	glfwSwapBuffers(window);
}