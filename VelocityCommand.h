#pragma once
#include "BaseCommand.h"
class VelocityCommand :
	public BaseCommand
{
private:

	//////// Control Variables ////////////
	Vec2f velocity;

public:

	//////// Mutators ////////////
	void SetVelocity(Vec2f _velocity);

	//////// Accessors ////////////
	Vec2f GetVelocity()const;
	

	//////// Method ////////////
	void Execute();
};

