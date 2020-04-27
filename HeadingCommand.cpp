#include "precompiled_header"
#include "HeadingCommand.h"

/// Set Heading setter ///
void HeadingCommand::SetHeading(float _heading) { heading = _heading; }


/// Heading Getter ///
float HeadingCommand::GetHeading()const { return heading; }


/// Method ///
void HeadingCommand::Execute()
{
	GetTarget()->SetHeading(heading);
}
