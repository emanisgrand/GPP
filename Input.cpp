#include "input.h"
using std::cout;

void InputHandler::handleInput()
{
   if (isPressed(BUTTON_X)) jump();
}

void InputHandler::jump()
{
    cout << "jump!\n";
}

bool InputHandler::isPressed(int val)
{
    if (val == BUTTON_X)
    {
        return true;
    }
    else
    {
        return false;
    }
}