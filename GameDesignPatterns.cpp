#include "pch.h"

class JumpCommand : public Command
{
public:
	virtual void execute() { jump(); }
};

class GrappleCommand : public Command
{
public:
	virtual void execute() { grapple(); }
};

class CoverCommand : public Command
{
public:
	virtual void execute() { cover(); }
};

class BlockCommand : public Command
{
public:
	virtual void execute() { block(); }
};

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


int main()
{	
	MenuItem* menu = new MenuItem;

	/// <summary>
	/// Pointer to a Command class, initialized to a custom command.
	/// </summary>
	/// <returns>Object.</returns>
	Command* button_x = new JumpCommand;
	Command* button_y = new BlockCommand;
	Command* button_a = new GrappleCommand;
	Command* button_b = new CoverCommand;
	
	do
	{
		DisplayMenu();
		cin >> menu->option;
		switch (menu->option)
		{
			DisplayMenu();
			case BUTTON_X:
				button_x->execute();
				break;
			case BUTTON_Y:
				button_y->execute();
				break;
			case BUTTON_A:
				button_a->execute();
				break;
			case BUTTON_B:
				button_b->execute();
				break;
			default:
				cout << "WRONG!\n";
				break;
		}
	} while (menu->option != 9);
	
}

