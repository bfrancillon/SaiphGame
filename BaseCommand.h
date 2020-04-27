#pragma once
#include "Model/Ship.h" 
class BaseCommand
{

	
private:

	//////// Model Variable ////////////

	Ship* target;

	//////// Control Variables ////////////
	
	float time;

public: 

	//////// Mutators ////////////
	void SetTarget(Ship* _ship);
	void SetTime(float _time);

	//////// Accessors ////////////
	Ship* GetTarget() const;
	float GetTime() const;

	/////// Functions ///////////
	void virtual Execute() = 0;



	
};

