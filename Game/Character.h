#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "mob.h"
#include "Creature.h"
#include <string>

class character : public Creature 
{
	friend class mob;

public:
	
	character::character(); 
	character::character(std::string, std::string,int, int, int, int, int, int, int, int);  

	void createClass();
	void rest();

	//Saving/Loading data

	void save(std::ofstream&);
	void load(std::ifstream&);
	bool checkData(std::ifstream&);		//Returns true if Data file its empty

	
	void experience(mob&mob);
	void levelUp();
	void increaseStats();
	void showStats();
	int playerLvl();

private:

	int mLevel;
	int mExpNextLvl;
	int mExp;
	

};



#endif // !CHARACTER_H
