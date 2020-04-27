#include "precompiled_header"
#include "Subject.h"


Subject::~Subject()
{
	NotifyObservers(Observer::SUBJECT_DEATH);
	obs.clear();
}

void Subject::Attach(Observer* _obs)
{
	obs.push_back(_obs);
}

void Subject::Detach(Observer* _obs)
{
	obs.remove(_obs);
}

void Subject::NotifyObservers(Observer::ObserverEvent _status)
{
	for (auto i = obs.begin(); i != obs.end(); ++i)
	{
		(*i)->Notification(_status);
	}
}
