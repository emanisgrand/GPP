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
	/// <summary>
	/// Declared but not defined.
	/// </summary>
	virtual string currently_assigned_command() { return " "; }

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
	virtual void execute(GameActor& actor) { actor.jump(); }
	virtual string currently_assigned_command() { return "jump."; }
};

class GrappleCommand : public Command
{
public:
	virtual void execute(GameActor& actor) { actor.grapple(); }
	virtual string currently_assigned_command() { return "grapple."; }
};

class CoverCommand : public Command
{
public:
	virtual void execute(GameActor& actor) { actor.cover(); }
	virtual string currently_assigned_command() { return "cover."; }
};

class BlockCommand : public Command
{
public:
	virtual void execute(GameActor& actor) { actor.block(); }
	virtual string currently_assigned_command() { return "block."; }
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