#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"


void LEVELCHOICE_UI::draw(GLFWwindow* window) {
	glViewport(-140, -220, 1000, 1000);
	glLoadIdentity();
	glScalef(0.0117, -0.0117, 1);
	glClearColor(0.164, 0.609, 0.394, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	print_string(-45, -40, choose, 0.836, 0.535, 0.387);
	print_string(-67, -20, level, 0.215, 0.394, 0.5);
	print_string(15, -70, back, 0.215, 0.394, 0.5);
	glfwSwapBuffers(window);
}