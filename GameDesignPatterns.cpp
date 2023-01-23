#include <iostream>
#include "input.h"
using std::cout;
using std::cin;
int main()
{
	InputHandler inputhandler;
	
	int option;

	do {
		cout << "Enter input.\n";
		cin >> option;
		
		switch (option)
		{
		case 0:
			inputhandler.handleInput();
			break;
		default:
			cout << "return.\n";
			break;
		}
	} while (option != 9);
}