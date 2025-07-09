#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"
FOOD* GAMING::randBonus() {
	srand(time(NULL));
	int r = rand() % 4;
	if (!r) return new MUSHROOM(map);
	if (r == 1) return new BANANA(map);
	if (r == 2) return new CHERRY(map);
	if (r == 3) return new LOLYPOP(map);
};
bool GAMING::start()
{

	bool s;
	bool x2, flag; char make = 0;
	char temp = window.CurWin;
	LEVEL_UI DUI(level);
	INPUTHANDLE input(window, 1, 1, 0, snake);
	state->timerset(15000, 0);
	while (window.CurWin == 5)  //тут вся игра
	{
		glfwPollEvents();
		DUI.draw(state);
		map->Draw();
		s = snake->Move(state, apple, bonus, map);
		if (s)window.CurWin = 7;
		if (state->checktime())
		{
			make = state->checkflags();
			if (make == 2) {
				bonus->del(map); delete[]bonus;
			}
			else if (make == 1)bonus = randBonus();
		}
		state->Flags(&x2, &flag);
		apple->Draw();
		if (flag)bonus->Draw();
		snake->Draw();
		glfwSwapBuffers(window.WIN());
		snake->wait();

	}
	if (window.CurWin == 7) {
		WINDOW death(7, 400, 300, "YOU ARE DEAD,NOT BIG SURPRISE");
		DEATH_UI dui;
		dui.draw(state, death);
		death.hold(7);
		death.close();
	}


	if (window.CurWin != 9)
	{
		scoreupdate();
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	window.close();
	if (window.CurWin == 5) {
		window.CurWin = temp; return 1;
	}
	window.CurWin = temp;;
	return 0;
}
GAMING::~GAMING() {
	bool f, x;
	state->Flags(&x, &f);
	if (f)delete bonus;
	delete map;
	delete snake;
	delete apple;
	delete state;
}
GAMING::GAMING(unsigned int mapsize, unsigned int snakesize,int lvl):window(WINDOW(5, 745, 900, "SNAKE")) {
	level = lvl;
	char s[3][12];
	FILE* scorus = fopen("score.txt", "r");
	fgets(s[0], 11, scorus);
	fgets(s[1], 11, scorus);
	fgets(s[2], 11, scorus);
	state = new GAMESTATE(atoi(s[lvl-1]));
	fclose(scorus);
	map = new MAP(mapsize, level);
	snake = new SNAKE(map, 500, snakesize);
	apple = new APPLE(map);
	bonus = randBonus();
};
void GAMING::scoreupdate() {
	FILE* scorus;
	char s[3][12];
	int h, sc;
	state->Score(&sc, &h);
	scorus = fopen("score.txt", "r");
	fgets(s[0], 11, scorus);
	fgets(s[1], 11, scorus);
	fgets(s[2], 11, scorus);
	fclose(scorus);
	scorus = fopen("score.txt", "w+");
	_itoa(h, s[level-1], 10);
	fputs(s[0], scorus);
	if (level == 1)fputc('\n', scorus);
	fputs(s[1], scorus);
	if(level==2)fputc('\n', scorus);
	fputs(s[2], scorus);
	fclose(scorus);
}