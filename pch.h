/// Add all includes and namespace accessors here.
#pragma once
#include <iostream>

#define BUTTON_X 0
#define BUTTON_Y 1
#define BUTTON_A 2
#define BUTTON_B 3

using std::cout;
using std::cin;

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


void jump();
void block();
void grapple();
void cover();