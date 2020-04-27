// DLL_STRAT.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "DLL_STRAT.h"



Strategy::Strategy()
{
	return;
}
void Strategy::Deflect(float& bulletHeading)
{
	// flip the projectile back at the enemy
	bulletHeading = bulletHeading * 12;
}
void Strategy::Destroy()
{
	delete this;
}

DLLSTRAT_API IDeflectionStrategy* CreateStrategy()
{
	return new Strategy();
}
