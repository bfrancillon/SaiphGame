#pragma once
#include<iostream>
#include<list>
#include "Model/Observer.h"
class Subject
{
std::list<Observer*> obs;

public:
	~Subject();
	void Attach(Observer*);
	void Detach(Observer*);
	void NotifyObservers(Observer::ObserverEvent _status);
};

