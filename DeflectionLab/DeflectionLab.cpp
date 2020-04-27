#include "framework.h"
#include "DeflectionLab.h"

#define PI			3.141592654f

Strategy::Strategy()
{
	return;
}

void Strategy::Deflect(float& bulletHeading)
{
	// flip the projectile back at the enemy
	bulletHeading = -bulletHeading;
}
void Strategy::Destroy()
{
	delete this;
}

DEFLECTIONLAB_API IDeflectionStrategy* CreateStrategy()
{
	return new Strategy();
}

