#pragma once
#define BUTTON_X 0
#include <iostream>
#include "command.h"

class InputHandler
{
private:
	/// <summary>
	/// TODO: returns true if the button value passed in matches
	/// the hard coded comparison
	/// </summary>
	/// <returns></returns>
	bool isPressed(int);

public:
	/// <summary>
	/// Delegate execution of actions to Commands
	/// </summary>
	void handleInput(int);

	/// <summary>
	/// Pointer to commands for each button.
	/// </summary>
	Command* button_x;
};