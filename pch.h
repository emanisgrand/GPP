/// Add all includes and namespace accessors here.
#pragma once
#include <iostream>

#define BUTTON_X 0
#define BUTTON_Y 1
#define BUTTON_A 2
#define BUTTON_B 3

using std::cout;
using std::cin;

#pragma region Menu Stuff
/// <summary>
/// Display the menu options. 
/// </summary>
void DisplayMenu();

/// <summary>
/// Data structure for creating the menu option variable.
/// </summary>
struct MenuItem
{
	int option;
};
#pragma endregion


#pragma region Command Stuff
/// <summary>
/// Used to create an object that will represent a game action
/// </summary>
class Command
{
public:
	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~Command() {};
	/// <summary>
	/// Run the method.
	/// </summary>
	virtual void execute() {};
};
#pragma endregion

#pragma region Actions
void jump();
void block();
void grapple();
void cover();
#pragma endregion

#pragma region Input Handler
/// <summary>
/// Should store pointer to a COMMAND for each BUTTON.
/// </summary>
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
};
#pragma endregion