#pragma once
#include "pch.h"

/// <summary>
/// Data structure for creating the menu option variable.
/// </summary>
struct MenuItem
{
	int option;
};

/// <summary>
/// Display the menu options. 
/// </summary>
void DisplayMenu();

/// <summary>
/// Go from a selection back to the menu?
/// TODO: I may not even need this.
/// </summary>
void MenuContinue();