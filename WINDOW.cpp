#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
WINDOW::WINDOW(char win, int width, int height, const char* name) :CurWin(win), window(glfwCreateWindow(width, height, name, NULL, NULL)) {
	if (!window) { glfwTerminate(); }
	glfwSetWindowPos(window, 30, 30);
	glfwMakeContextCurrent(window);
};

GLFWwindow* WINDOW::WIN() { return window; }
char WINDOW::hold(char cur)
{
	while (CurWin == cur)
	{
		glfwPollEvents();
	}
	return CurWin;
}
void WINDOW::close() { glfwDestroyWindow(window); }