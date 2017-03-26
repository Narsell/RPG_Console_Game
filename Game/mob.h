
#ifndef MOB_H
#define MOB_H


#include "Weapon.h"
#include <string>

class character;

class mob {

	friend class character;

public:

	mob::mob();
	mob::mob(std::string, std::string, int, int, int, int, int);

	void nTakeDamage(int);
	bool nIsDead();
	void mobAttack(character&player); 
	
	//DATA ACCESORS:

	int mobHealth ();
	std::string mobName();

private:

	std::string nName;
	int nHealth;
	int nArmor;
	int xpReward;
	bool nDead;
	Weapon nWeapon;

	static int mob_count; //static counter for mobs created.
	
};




#endif // !MOB_H
