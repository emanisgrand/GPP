#include "pch.h"

int main()
{
	InputHandler inputhandler;
	MenuItem* menu = new MenuItem;

	Command* button_x = new JumpCommand;
	
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
			default:
				cout << "WRONG!\n";
				break;
		}
	} while (menu->option != 9);
	
}