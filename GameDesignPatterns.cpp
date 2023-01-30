#include "pch.h"
static GameActor* actor = new GameActor();

void MainMenu()
{
	system("cls");
	cout << "\t THE GAME " << endl;
	cout << "1. Play\n";
	cout << "2. Options" << endl;
}

void InputHandler::buttonConfig()
{
	BUTTON input;
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

