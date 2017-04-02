
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
	xpReward = 0;
	++MOB_COUNT;
}

mob::mob(string name, string wName, int lowR, int highR, int health, int defense, int reward)
{
	mName = name;
	creatureWeapon.wName = wName;
	creatureWeapon.wRange.Rlow = lowR;
	creatureWeapon.wRange.RHigh = highR;
	mHealth = health;
	mArmor = defense;
	xpReward = reward;
	++MOB_COUNT;
}



