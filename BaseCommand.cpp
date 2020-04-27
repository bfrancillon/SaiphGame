#include "precompiled_header"
#include "BaseCommand.h"



/// Set Ship setter ///
void BaseCommand::SetTarget(Ship* _ship) { target = _ship; }


/// Set Time setter ///
void BaseCommand::SetTime(float _time) { time = _time; }


/// Ship Getter ///
Ship* BaseCommand::GetTarget()const { return target; }


/// Time Getter ///
float BaseCommand::GetTime()const { return time; }



