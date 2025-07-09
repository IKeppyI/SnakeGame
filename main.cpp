#include"SNAKE.h"

int main()
{

	if (!glfwInit()) {              //Включаем GLFW
		return -1;
	}
	char curwin;
	while (1)
	{
		WINDOW menus(1, 600, 700, "SNAKE");
		INPUTHANDLE inp(menus, 1, 0, 1, nullptr);
		GAMING* game=0;
		bool again;
		MENU_UI ui;
		ui.draw(menus.WIN());
		curwin=menus.hold(1);
		if (curwin == 0)break;
		if (curwin >= 5 and curwin <= 7) 
		{
			k:
			menus.close();
			if (curwin == 5) {
				game= new GAMING(30, 3,1);
			}
			else if (curwin == 6) {
				game = new GAMING(30, 3,2);
			}
			else if (curwin == 7)
			{
				game = new GAMING(30, 3,3);
			}
			again = game->start();
			delete game;
			if (again)goto k;
		}
		
	}
	glfwTerminate;
	return 0;
}

