
#ifndef MONSTER_H
#define MONSTER_H


#include "Weapon.h"
#include "Creature.h"

#include <string>


class Player;

class Monster : public Creature {

	friend class Player;

public:

	Monster::Monster();
	Monster::Monster(std::string, std::string, int, int, int, int, int, int);

private:

	int mXpReward;
	static int MOB_COUNT; 
	
};




#endif // !MOB_H
