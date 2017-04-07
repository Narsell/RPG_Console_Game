#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include "Weapon.h"

class Creature
{

public:
	
	Creature();
	Creature(std::string, std::string, int, int, int, int, int);
	void TakeDamage(int);
	void Attack(Creature*Enemy);

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


