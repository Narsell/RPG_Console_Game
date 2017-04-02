#include <iostream>

#include "Creature.h"
#include "Random.h"

int Creature::Health()
{
	return mHealth;
}

bool Creature::IsDead()
{
	return mHealth <= 0;

}

void Creature::TakeDamage(int dmg)
{
	mHealth -= dmg;
}

void Creature::Attack(Creature*Enemy)
{

	int dmg = Random(creatureWeapon.wRange.Rlow, creatureWeapon.wRange.RHigh) - Enemy->mArmor;
	Enemy->TakeDamage(dmg);
	system("pause");
	
}

std::string Creature::Name()
{
	return mName;
}
