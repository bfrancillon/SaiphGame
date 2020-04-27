#include "precompiled_header"
#include "VelocityCommand.h"

/// Set Velocity setter ///
void VelocityCommand::SetVelocity(Vec2f _velocity) { velocity = _velocity;}


/// Velocity Getter ///
Vec2f VelocityCommand::GetVelocity()const { return velocity; }

/// Method ///
void VelocityCommand::Execute()
{
	GetTarget()->SetVelocity(velocity);
}