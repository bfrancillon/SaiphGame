#pragma once
#include "BaseCommand.h"
class HeadingCommand :
	public BaseCommand
{
	//////// Control Variables ////////////
	float heading;

public:

	//////// Mutators ////////////
	void SetHeading(float _heading);

	//////// Accessors ////////////
	float GetHeading()const;

	//////// Method ////////////
	void Execute();


};

