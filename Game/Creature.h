#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include "Weapon.h"

class Creature
{

public:
	
	void TakeDamage(int);

	//Accesors

	int Health();
	bool IsDead();
	std::string Name();

protected:

	std::string mName;
	Weapon creatureWeapon;
	int mHealth;
	int mMaxHealth;
	int mArmor;
	bool mDead;


};

#endif // !CREATURE_H


