#include "pch.h"

int main()
{
	InputHandler inputhandler;
	
	MenuItem* menu = new MenuItem;

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