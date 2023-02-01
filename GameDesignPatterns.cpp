#include "pch.h"
static GameActor* actor = new GameActor();

void MainMenu()
{
	system("cls");
	cout << "\t THE GAME " << endl;
	cout << "1. Play\n";
	cout << "2. Options" << endl;
}

/// <summary>
/// Menu item.
/// </summary>
void DisplayCommands()
{
	cout << "\n(B)lock";
	cout << "\n(C)over";
	cout << "\n(G)rapple";
	cout << "\n(J)ump\n" << endl;
}

void InputHandler::displayCurrentConfig()
{
	// display assignment for A
	cout << "A: ";
	if (button_a_cmd_delegate != nullptr)
	{
		cout << button_a_cmd_delegate->currently_assigned_command() << endl;
	}
	else
	{
		cout << "NOT ASSIGNED" << endl;
	}

	// display assignment for B
	cout << "B: ";
	if (button_b_cmd_delegate != nullptr)
	{
		cout << button_b_cmd_delegate->currently_assigned_command() << endl;
	}
	else
	{
		cout << "NOT ASSIGNED" << endl;
	}

	// display assignment for X
	cout << "X: ";
	if (button_x_cmd_delegate != nullptr)
	{
		cout << button_x_cmd_delegate->currently_assigned_command() << endl;
	}
	else
	{
		cout << "NOT ASSIGNED" << endl;
	}

	// display assignment for Y
	cout << "Y: ";
	if (button_y_cmd_delegate != nullptr)
	{
		cout << button_y_cmd_delegate->currently_assigned_command() << endl;
	}
	else
	{
		cout << "NOT ASSIGNED" << endl;
	}
}

// TODO: Redraw menu.
void InputHandler::buttonConfig()
{
	BUTTON input;
	char assignment;
	Command* cmdReg;

	do {
		system("cls");
		cout << "\t Assign buttons:" << endl;

		displayCurrentConfig();

		cout << "choose which Command to reassign\n";
		DisplayCommands();
		cin >> assignment;

		if (assignment == 'C' || assignment == 'c')
		{
			cmdReg = new CoverCommand();
		}
		else if (assignment == 'B' || assignment == 'b')
		{
			cmdReg = new BlockCommand();
		}
		else if (assignment == 'J' || assignment == 'j')
		{
			cmdReg = new JumpCommand();
		}
		else if (assignment == 'G' || assignment == 'g')
		{
			cmdReg = new GrappleCommand();
		}

		cout << "choose which button to assign " << cmdReg->currently_assigned_command()<< " to.\n(A)\n(B)\n(X)\n(Y)\n";
		
		cin >> assignment;

		if (assignment == 'a' || assignment == 'A')
		{
			cout << "Reassigning A..." << endl;
			button_a_cmd_delegate = cmdReg;
		}
		else if (assignment == 'b' || assignment == 'B')
		{
			cout << "Reassigning B..." << endl;
			button_b_cmd_delegate = cmdReg;
		}
		else if (assignment == 'x' || assignment == 'X')
		{
			cout << "Reassigning X..." << endl;
			button_x_cmd_delegate = cmdReg;
		}
		else if (assignment == 'y' || assignment == 'Y')
		{
			cout << "Reassigning Y..." << endl;
			button_y_cmd_delegate = cmdReg;
		}
		else
		{
			cout << "please choose a valid option.\n";
		}

		displayCurrentConfig();

		cout << "\n\nstanding by...\n";
		
		cin >> input;
	
	} while (input != 9);
}

void InputHandler::handleInput()
{	
	BUTTON pressed;
	do
	{
		cout << "\tawaiting input...\n";
		cin >> pressed;
		switch (pressed)
		{
		case BUTTON_A:
			button_a_cmd_delegate->execute(*actor);
			break;
		case BUTTON_B:
			button_b_cmd_delegate->execute(*actor);
			break;
		case BUTTON_X:
			button_x_cmd_delegate->execute(*actor);
			break;
		case BUTTON_Y:
			button_y_cmd_delegate->execute(*actor);
			break;
		default:
			cout << "DRONE";
			break;
		}
	} while (pressed != 9);
}

int main()
{
	InputHandler ih = InputHandler();
	BUTTON input;
	do {
		MainMenu();
		cin >> input;
		switch (input)
		{
		case 1:
			ih.handleInput();
			break;
		case 2:
			// set keys option
			ih.buttonConfig();
			break;
		default:
			"thank you.";
			break;
		}
	} while (input != 9);
	ih.handleInput();
}

