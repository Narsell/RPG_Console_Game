
#include <iostream>
#include <string>

#include "mob.h"
#include "Random.h"
#include "Weapon.h"
#include "Character.h"


using namespace std;


int mob::MOB_COUNT = 0;

mob::mob()
{
	mName = "Default";
	mHealth = 1;
	mArmor = 1;
	creatureWeapon.wName = "Defautl Weapon";
	creatureWeapon.wRange.Rlow = 0;
	creatureWeapon.wRange.RHigh =0;
	mXpReward = 0;
	++MOB_COUNT;
}

mob::mob(string Name, string weaponName, int rLow, int rHigh, int Health, int maxHealth, int Armor, int Reward)
	:Creature(Name, weaponName, rLow, rHigh, Health, maxHealth, Armor), mXpReward(Reward)
{
	++MOB_COUNT;
}



