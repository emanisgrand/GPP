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
	cout << "\n(J)ump";
}

// TODO: Redraw menu.
void InputHandler::buttonConfig()
{
	BUTTON input;
	char assignment;

	do {
		system("cls");
		cout << "\t Assign buttons:" << endl;
		// display currently assigned buttons
		cout << "A: ";
		if (button_a_cmd_delegate != nullptr)
		{
			cout << button_a_cmd_delegate->currently_assigned_command() << endl;
		}
		else
		{
			cout << "NOT ASSIGNED" << endl;
		}

		cout << "choose which button to reassign\n";
		cin >> assignment;
		
		if (assignment == 65 || assignment == 97)
		{
			cout << "Reassigning A" << endl;

			cout << "Bind what to A?";
			DisplayCommands();
		}
		else
		{
			cout << "please choose a valid option.\n";
		}

		cout << "\n\nstanding by...";
		cin >> assignment;
		if (assignment == 'B' || assignment == 'b')
		{
			button_a_cmd_delegate = new BlockCommand();
			cout << "A is now set to Block!";
		}

		cout << "\n\nstanding by...";
		
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
			/// <summary>
			/// what is going on here?
			/// </summary>
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

