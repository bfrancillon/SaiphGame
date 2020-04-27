#pragma once


class Observer {
public:
	enum ObserverEvent{ACTIVATE, SUBJECT_DEATH};
	virtual void Notification(ObserverEvent _state) = 0;
};