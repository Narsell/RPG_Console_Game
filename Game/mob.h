
#ifndef MOB_H
#define MOB_H


#include "Weapon.h"
#include "Creature.h"

#include <string>


class character;

class mob : public Creature {

	friend class character;

public:

	mob::mob();
	mob::mob(std::string, std::string, int, int, int, int, int);

private:

	int xpReward;
	static int MOB_COUNT; //static counter for mobs created.
	
};




#endif // !MOB_H
