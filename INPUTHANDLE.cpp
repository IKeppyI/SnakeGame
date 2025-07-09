#define _CRT_SECURE_NO_WARNINGS
#include "SNAKE.h"

INPUTHANDLE::INPUTHANDLE(WINDOW& win, bool m, bool k,bool type, SNAKE* snakepoint){
	glfwSetWindowUserPointer(win.WIN(), this); 
    if (m) {
        jerry = new MOUSE(win);
        if(type)glfwSetMouseButtonCallback(win.WIN(), MmouseCallback);
        else glfwSetMouseButtonCallback(win.WIN(), GmouseCallback);
    }
    if (k){key = new KEYBOARD(win, snakepoint); glfwSetKeyCallback(win.WIN(), keyCallback); }
};

void INPUTHANDLE::GmouseCallback(GLFWwindow* window, int button, int action, int mods) {
    INPUTHANDLE* inputHandle = static_cast<INPUTHANDLE*>(glfwGetWindowUserPointer(window));
    if (inputHandle && inputHandle->jerry) {
        inputHandle->jerry->handleGMouseInput(window, button, action, mods);
    }
}
void INPUTHANDLE::MmouseCallback(GLFWwindow* window, int button, int action, int mods) {
    INPUTHANDLE* inputHandle = static_cast<INPUTHANDLE*>(glfwGetWindowUserPointer(window));
    if (inputHandle && inputHandle->jerry) {
        inputHandle->jerry->handleMMouseInput(window, button, action, mods);
    }
}
void INPUTHANDLE::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    INPUTHANDLE* inputHandle = static_cast<INPUTHANDLE*>(glfwGetWindowUserPointer(window));
    if (inputHandle && inputHandle->key) {
        inputHandle->key->handleKeyInput(key, scancode, action, mods);
    }
}
INPUTHANDLE::~INPUTHANDLE()
{
	delete key;
	delete jerry;
}