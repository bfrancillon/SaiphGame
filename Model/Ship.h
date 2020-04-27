// Ship.h
// Class to manage player avatar
// Code by Derek Bliss
// Created April 17, 2008
// Last updated October 14, 2008
//
#ifndef SHIP_H
#define SHIP_H

#include "MovingObject.h"
#include "Deflector.h"
#include "Bullet.h"
#define MAX_ARMOR					200.0f

class Ship : public MovingObject
{
	bool	afterburnerFlag;// Is this ship using afterburners?
	int		cost;			// Cost of this ship
	float	armor;			// Last line of defense before you go boom!
	float	shield;			// Current power of shields
	float	battery;		// Current energy reserves
	float	lastFired;		// Time since last fired
	float	afterburner;	// Energy left for afterburner power
	Deflector* deflector;

public:
	Ship();
	virtual ~Ship();

	// mutators
	void SetAfterburnerFlag(bool _afterburnerFlag);
	void SetCost(int _cost);
	void SetArmor(float _armor);
	void SetShield(float _shield);
	void SetBattery(float _battery);
	void SetLastFired(float _time);
	void SetAfterburner(float _energy);
	void SetDeflector(Deflector* def);

	// accessors
	bool GetAfterburnerFlag() const;
	int GetCost() const;
	float GetArmor() const;
	float GetShield() const;
	float GetBattery() const;
	float GetLastFired() const;
	float GetAfterburner() const;
	Deflector* GetDeflector();

	// interface methods
	void Heartbeat(float _delta);
	virtual bool Ship::Collide(const BaseObject& _in) const;
	virtual bool Ship::Collide(Bullet& _in);
};

#endif