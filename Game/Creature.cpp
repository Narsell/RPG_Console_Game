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

Creature::Creature()
	: mName("Default Name"), mHealth(1), mMaxHealth(1), mArmor(1), mDead(0)
{
	
	creatureWeapon.wName = "Default Weapon";
	creatureWeapon.wRange.Rlow = 0;
	creatureWeapon.wRange.RHigh = 1;

}

Creature::Creature(std::string Name, std::string WeaponName, int rLow, int rHigh, int Health, int maxHealth, int Armor)

	: mName(Name), mHealth(Health), mMaxHealth(maxHealth), mArmor(Armor)
{
	creatureWeapon.wName = WeaponName;
	creatureWeapon.wRange.Rlow = rLow;				//For some reason, i can't put theese on the member intitialization list >:(
	creatureWeapon.wRange.RHigh = rHigh;
}

void Creature::TakeDamage(int dmg)
{
	mHealth -= dmg;
}

void Creature::Attack(Creature*Enemy)
{

	int dmg = Random(creatureWeapon.wRange.Rlow, creatureWeapon.wRange.RHigh) - Enemy->mArmor;
	Enemy->TakeDamage(dmg);
	std::cout << mName << " did " << dmg << " damage to " << Enemy->mName << std::endl;
	system("pause");
	
}

std::string Creature::Name()
{
	return mName;
}
