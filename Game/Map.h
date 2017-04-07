#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include "Monster.h"

class map {

public:

	map::map();
	int getX();
	int getY();
	void move();
	Monster*getEncounter();

private:

	int mX;
	int mY;

};


#endif // !MAP_H
