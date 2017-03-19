#ifndef MAP_H
#define MAP_H

#include "Character.h"
#include "mob.h"

class map {

public:

	map::map();
	int getX();
	int getY();
	void move();

	mob*getEncounter();

private:

	int mX;
	int mY;

};


#endif // !MAP_H
