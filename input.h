#pragma once
#define BUTTON_X 0
#define BUTTON_Y 1
#define BUTTON_A 2
#define BUTTON_B 3
#include <iostream>

class InputHandler
{
private:
	bool isPressed(int);
public:
	void handleInput();
	void jump();
};