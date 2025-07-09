#define _CRT_SECURE_NO_WARNINGS
#include <WINDOWS.h>
#include <stdio.h>
#include <gl/gl.h>
#include <C:\Users\ыўсыў ўыў\ooplabs\lab2\lab2\libs\glfw3.h>	
#include <stdlib.h>
#include <thread>
#include <time.h>
#include<C:\Users\ыўсыў ўыў\ooplabs\lab2\lab2\libs\stb_easy_font.h>
enum Cell {
	Empty,
	Snake,
	Food,
	Block,
	Bonus
};
class MAP {
protected:
	char level;
	short size;
	Cell** A;
public:
	MAP(unsigned int size,char lvl);
	void Draw();
	short Size();
	void change(short x, short y, Cell type);
	Cell type(short x, short y);
	char Level();
	~MAP();
};
class SNAKEBody {
private:
	short x;
	short y;
	char side;
	bool turn;
	SNAKEBody* back;
	friend class KEYBOARD;
public:
	SNAKEBody(short x1, short y1, const char side1, SNAKEBody* back1);
	void pos(short* x1, short* y1);
	void direct(char* side1, bool* turn1);
	void body(char* side1, bool* turn1);
	void change(short x1, short y1, bool turn1, const char side1, SNAKEBody* back1);
	void clr();
	SNAKEBody* Back();
	void Draw(SNAKEBody* prev);
};
class GAMESTATE {
private:
	int score;
	bool Bonus;
	bool x2;
	int foodtime;
	int hScore;
	int counter;

public:
	GAMESTATE(int num);
	void timerset(int time,bool drop);
	void setx2(bool t);
	bool scoreup();
	void Score(int* s, int* h);
	void Flags(bool* x, bool* B);
	char checkflags();
	bool checktime();
};
class SNAKE;
class UI;
class WINDOW;
class FOOD
{
protected:
	short x;
	short y;
public:
	FOOD(MAP* map);
	void posgen(MAP* map);
	virtual void Draw() = 0;
	virtual void make(MAP* map) = 0;
	virtual void get_effect(SNAKE& snake, GAMESTATE* state, MAP* map) = 0;
	void pos(short* x1, short* y1);
	void del(MAP* map);
};
class MUSHROOM :public FOOD {
public:
	MUSHROOM(MAP* map);
	void make(MAP* map)override;
	void Draw() override;
	void get_effect(SNAKE& snake, GAMESTATE* state, MAP* map) override;
};
class APPLE :public FOOD {
public:
	APPLE(MAP* map);
	void make(MAP* map)override;
	void Draw()override;
	void get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)override;
};
class BANANA :public FOOD {
public:
	BANANA(MAP* map);
	void make(MAP* map)override;
	void Draw()override;
	void get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)override;
};
class CHERRY :public FOOD {
public:
	CHERRY(MAP* map);
	void make(MAP* map)override;
	void Draw()override;
	void get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)override;
};
class LOLYPOP :public FOOD {
public:
	LOLYPOP(MAP* map);
	void make(MAP* map)override;
	void Draw()override;
	void get_effect(SNAKE& snake, GAMESTATE* state, MAP* map)override;
};
class SNAKE {
private:
	SNAKEBody* Head;
	SNAKEBody* Tail;
	unsigned int size;
	float speed;
	friend class KEYBOARD;
public:
	SNAKE(MAP* map, unsigned int sp, unsigned int sz);
	void SpeedChng(bool UpOrDown, float dif);
	void Grow(MAP* map);
	bool Move(GAMESTATE* cur, FOOD* apple, FOOD* bonus, MAP* map);
	void Draw();
	void Decrease(short num, MAP* map);
	unsigned int Size();
	void wait();
	~SNAKE();
};
class MOUSE {
private:
	char* CurWin;
public:
	MOUSE(WINDOW& Win);
	void handleGMouseInput(GLFWwindow* window, int button, int action, int mods);
	void handleMMouseInput(GLFWwindow* window, int button, int action, int mods);
};
class KEYBOARD {
private:
	char* CurWin;
	SNAKE* snake;
	bool press;
public:
	KEYBOARD(WINDOW& win, SNAKE* snak);
	void handleKeyInput(int key, int scancode, int action, int mods);
	void menu(GLFWwindow* window, int key, int scancode, int action, int mods);
};
class WINDOW {
	protected:
		char CurWin;
		GLFWwindow* window;
		friend class GAMING;
		friend class MOUSE;
		friend class KEYBOARD;
	public:
		WINDOW(char win, int width, int height, const char* name);
		GLFWwindow* WIN();
		char hold(char cur);
		void close();
	};

class UI {
protected:
	char back[5] = "BACK";
public:
	void print_string(float x, float y, char* text, float r, float g, float b);
	virtual void draw(GAMESTATE* state) = 0;
	virtual void draw(GLFWwindow* window) = 0;
	virtual void draw(GAMESTATE* state, WINDOW& death) = 0;
};
class LEVEL_UI :public UI
{
private:
	char hscore[100] = "HIGH SCORE: ";
	char score[22] = "\n\nSCORE: ";
	char bonus[14] = "X2 BONUS BABY";
	int level;
	char lvlstr[3][15] = {"LEVEL: 1/3" ,"LEVEL: 2/3","LEVEL: 3/3" };
public:
	LEVEL_UI(int lvl);
	void draw(GAMESTATE* state)override;
	void draw(GLFWwindow* window)override {};
	void draw(GAMESTATE* state, WINDOW& death)override {};

};

class MENU_UI :public UI {
private:
	char menu[33] = "NEW GAME\n  SCORE\n  HELP\n  QUIT";
	char gamename[7] = "SNAKUS";
public:
	void draw(GLFWwindow* window) override;
	void draw(GAMESTATE* state)override{};
	void draw(GAMESTATE* state, WINDOW& death)override {};
};
class DEATH_UI :public UI {
private:
	char over[10] = "GAME OVER";
	char leave[21] = "AGAIN    LEAVE";
	char total[33] = "Your total score is: ";
	const char* insults[11] = { "God,it was really\npainful to watch...", "Yikes man, is that\nreally this hard?", "My mom literaly plays\nbetter than you", "Jesus! did you even\nread the manual?", "Oh,1700 strings\nof coding for this...", "don't bother\npressing AGAIN button","WHAT THE ACTUAL\n**** WAS THAT, DUDE?","Soo, let's pretend\nit never happened","It's just snake,you\ncan't be serious","Did you not get\nthe rules or what?!","ahaha,If i knew\ni would make level 0" };
public:
	void ChooseInsult(char* text);
	void draw(GAMESTATE* state)override {};
	void draw(GLFWwindow* window)override {};
	void draw(GAMESTATE* state, WINDOW& death) override;
};
class LEVELCHOICE_UI :public UI {
private:
	char choose[13] = "CHOOSE LEVEL";
	char level[44] = "      LEVEL 1\n\n      LEVEL 2\n\n      LEVEL 3";
public:
	void draw(GLFWwindow* window) override;
	void draw(GAMESTATE* state, WINDOW& death) override {};
	void draw(GAMESTATE* state)override {};
};
class SCORE_UI :public UI {
private:
	FILE* scorus;
	char level[84] = "    HIGH SCORE\n\n  LEVEL 1:           \n\n  LEVEL 2:           \n\n  LEVEL 3:           ";
public:
	void draw(GLFWwindow* window);
	void draw(GAMESTATE* state, WINDOW& death) override {};
	void draw(GAMESTATE* state)override {};
};
class HELP_UI :public UI {
private:
	FILE* scorus;
	char idiot[130] = "       HELP\n\n  Wow,what a guy\n being very funny.\n Look at me i need\n help to play snake\ngoo goo gaga im baby\n\n  GET A LIFE MAN!";
public:
	void draw(GLFWwindow* window) override;
	void draw(GAMESTATE* state, WINDOW& death) override {};
	void draw(GAMESTATE* state)override {};
};
class GAMING {
protected:
	int level;
	SNAKE* snake;
	MAP* map;
	GAMESTATE* state;
	FOOD* apple;
	FOOD* bonus;
	WINDOW window;
public:
	GAMING(unsigned int mapsize, unsigned int snakesize,int lvl);
	~GAMING();
	FOOD* randBonus();
	void scoreupdate();
	bool start();
};
class INPUTHANDLE {
private:
	KEYBOARD* key;
	MOUSE* jerry;
public:
	INPUTHANDLE(WINDOW& win, bool m, bool k, bool type, SNAKE* snakepoint);
	static void MmouseCallback(GLFWwindow* window, int button, int action, int mods);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void GmouseCallback(GLFWwindow* window, int button, int action, int mods);
	~INPUTHANDLE();
};