/// Add all includes and namespace accessors here.
#pragma once
#include <iostream>
#include <string>

#define BUTTON_X 0
#define BUTTON_Y 1
#define BUTTON_A 2
#define BUTTON_B 3

typedef int BUTTON;

using std::string;
using std::cout;
using std::cin;
using std::endl;

#pragma region Actors & Actions
class GameActor
{
public:
	GameActor()
	{
		cout << "game actor initialized\n";
	}

	void jump();
	void block();
	void grapple();
	void cover();
};
#pragma endregion

#pragma region Command Stuff
/// <summary>
/// Base class represents a triggerable game command
/// </summary>
class Command
{
public:
	virtual string currently_assigned_command();

	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~Command() {};
	
	/// <summary>
	/// Run the method.
	/// </summary>
	virtual void execute(GameActor& actor) {};
};

#pragma region Subclasses for each action

class JumpCommand : public Command
{
public:
	virtual string currently_assigned_command() { return "jump"; }
	virtual void execute(GameActor& actor) { actor.jump(); }
};

class GrappleCommand : public Command
{
public:

	virtual string currently_assigned_command() { return "grapple"; }
	virtual void execute(GameActor& actor) { actor.grapple(); }
};

class CoverCommand : public Command
{
public:

	virtual string currently_assigned_command() { return "cover"; }
	virtual void execute(GameActor& actor) { actor.cover(); }
};

class BlockCommand : public Command
{
public:

	virtual string currently_assigned_command() { return "block"; }
	virtual void execute(GameActor& actor) { actor.block(); }
};

#pragma endregion
#pragma endregion

#pragma region Input Handler
class InputHandler
{
public:
	/// <summary>
	/// Run the appropriate button command delegate.
	/// </summary>
	void handleInput();

	/// <summary>
	/// Configure the buttons with access to the commands.
	/// </summary>
	void buttonConfig();
private:
	/// <summary>
	/// Store a pointer to a command for each button
	/// </summary>
	Command* button_x_cmd_delegate;
	Command* button_y_cmd_delegate;
	Command* button_a_cmd_delegate;
	Command* button_b_cmd_delegate;
};
#pragma endregion