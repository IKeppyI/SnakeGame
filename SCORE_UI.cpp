#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"


void SCORE_UI::draw(GLFWwindow* window) {
	char c;
	scorus = fopen("score.txt", "r");
	char* p = &level[25];
	while (!feof(scorus))
	{
		c = fgetc(scorus);
		if (c == '\n') { while (*p != ':')p++; }
		else { p++; *p = c; }
	}
	fclose(scorus);
	glViewport(-140, -220, 1000, 1000);
	glLoadIdentity();
	glScalef(0.009, -0.009, 1);
	glClearColor(0.164, 0.609, 0.394, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	print_string(-70, -60, level, 0.836, 0.535, 0.387);
	glScalef(1.3, 1.3, 1.3);
	print_string(15, -70, back, 0.215, 0.394, 0.5);
	glfwSwapBuffers(window);


}


