#include "precompiled_header"
#include "MotherShip.h"
#include "VelocityCommand.h"
#include "HeadingCommand.h"
#include "BaseCommand.h"
#include "View/ViewManager.h"


/// Constructor ///
MotherShip::MotherShip(const Ship &_ship): Ship(_ship)
{
	
}

 /// Destructor ///
MotherShip::~MotherShip()
{
	CleanUpCommands();
	for (int i = shadows.size() - 1; i > -1; i--)
	{
		ViewManager::GetInstance().RemoveObject(shadows[i]);
		delete shadows[i];

	}
	shadows.clear();
}

/// Methods ///
void MotherShip::AddShadow(Ship* shadow)
{
	
	shadows.push_back(shadow);
	
}

void MotherShip::Heartbeat(float _delta)
{
	Ship::Heartbeat(_delta);
	ProcessCommands(_delta);

	if (GetAfterburnerFlag())
	{
		
		float timeDelta = 0.05f;

		
		for (int i = 0; i < shadows.size(); ++i)
		{
		
			VelocityCommand* drift = new VelocityCommand();
			drift->SetTarget(shadows[i]);
			drift->SetTime(timeDelta);
			drift->SetVelocity(Ship::GetVelocity());
			commands.push_back(drift);

			HeadingCommand* direction = new HeadingCommand();
			direction->SetTarget(shadows[i]);
			direction->SetTime(timeDelta);
			direction->SetHeading(Ship::GetHeading());
			commands.push_back(direction);
			shadows[i]->Heartbeat(_delta);

			timeDelta += 0.05f;
		}


	}
	else if (GetAfterburnerFlag() == false)
		CleanUpCommands();
}

void MotherShip::CleanUpCommands()
{
	for (int i = 0; i < commands.size(); i++)
	{
		delete commands[i];
		
	}
	commands.clear();

	for (int i = 0; i < shadows.size(); i++)
	{
		
		shadows[i]->SetPosition(this->GetPosition());
		shadows[i]->SetHeading(this->GetHeading());
		shadows[i]->SetVelocity(0, 0);
	}


	
}

void MotherShip::ProcessCommands(float _delta)
{
	
	for (unsigned int i = _delta; i < commands.size(); ++i)
	{

		commands[i]->SetTime((commands[i]->GetTime()) - _delta);

		if (commands[i]->GetTime() <= 0)
		{
			commands[i]->Execute();
			delete commands[i];
			commands.erase(commands.begin() + i);
			i--;
		}

	}
}
