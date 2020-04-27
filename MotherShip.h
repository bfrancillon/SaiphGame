#pragma once
#include "Model/Ship.h"  
#include "AbstractState.h"
#include "BaseCommand.h"

class Ship;
class BaseCommand;
class HeadingCommand;
class VelocityCommand;
class MotherShip :
	public Ship
{
public:


	/// Constructor ///
	MotherShip(const Ship& _ship);

	/// Destructor ///
	~MotherShip();

	/// Gameplay object ///
	std::vector<Ship*> shadows;
	// *** Delayed commands *** //
	std::vector<BaseCommand*> commands;
	/// methods ///
	void Heartbeat(float _delta);
	void AddShadow(Ship* shadow);

	
private:
	void CleanUpCommands();
	void ProcessCommands(float _delta);
};

