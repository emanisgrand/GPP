#include "input.h"
using std::cout;

Command* button_x = new JumpCommand;

void InputHandler::handleInput(int button)
{
    switch (button)
    {
    case BUTTON_X:
        button_x->execute();
        break;
    default:
        cout << "button not set.";
        break;
    }
}

bool InputHandler::isPressed(int val)
{
    switch (val)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        return true;
    default:
        return false;
    }
}