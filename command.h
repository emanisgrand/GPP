#pragma once
#include "Actions.h"

/// <summary>
/// Used to create an object that will represent a game action
/// </summary>
class Command
{
public:
	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~Command() {};
	/// <summary>
	/// Run the method.
	/// </summary>
	virtual void execute() {};
};

class JumpCommand : public Command
{
public:
	virtual void execute() { jump(); }
};

class GrappleCommand : public Command
{
public:
	virtual void execute() { grapple(); }
};

class CoverCommand : public Command
{
public:
	virtual void execute() { cover(); }
};

class BlockCommand : public Command
{
public:
	virtual void execute() { block(); }
};