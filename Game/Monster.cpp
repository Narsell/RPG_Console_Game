
#include <iostream>
#include <string>

#include "Monster.h"
#include "Random.h"

int Monster::MOB_COUNT = 0;

Monster::Monster()
	:Creature("Default Name", "Default Weapon", 0, 1, 1, 1, 1), mXpReward(1)
{

	++MOB_COUNT;
}

Monster::Monster(std::string Name, std::string weaponName, int rLow, int rHigh, int Health, int maxHealth, int Armor, int Reward)
	:Creature(Name, weaponName, rLow, rHigh, Health, maxHealth, Armor), mXpReward(Reward)
{
	++MOB_COUNT;
}



