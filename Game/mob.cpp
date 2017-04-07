
#include <iostream>
#include <string>

#include "mob.h"
#include "Random.h"
#include "Weapon.h"
#include "Character.h"


using namespace std;


int mob::MOB_COUNT = 0;

mob::mob()
	:Creature("Default Name", "Default Weapon", 0, 1, 1, 1, 1), mXpReward(1)
{

	++MOB_COUNT;
}

mob::mob(string Name, string weaponName, int rLow, int rHigh, int Health, int maxHealth, int Armor, int Reward)
	:Creature(Name, weaponName, rLow, rHigh, Health, maxHealth, Armor), mXpReward(Reward)
{
	++MOB_COUNT;
}



