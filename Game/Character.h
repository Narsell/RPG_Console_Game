#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "mob.h"

#include <string>

class character
{

public:
	
	character::character(); // <--- default constructor declaration
	character::character(std::string, std::string,int, int, int, int, int, int, int, int);  // <--- custom constructor declaration 

	void createClass();
	void rest();

	//Saving/Loading data

	void save(std::ofstream&);
	void load(std::ifstream&);
	bool checkData(std::ifstream&);		//Returns true if Data file its empty

	//Combat

	bool mIsDead();
	void mTakeDamage(int);
	bool playerAttack(mob&mob);  //Returns true if attempt to run rolls true
	void experience(mob&mob);
	void levelUp();
	void increaseStats();

	//Accesors

	void showStats();
	int playerHealth();
	int playerArmor();

private:

	std::string mName;
	Weapon playerWeapon;
	int mLevel;
	int mExpNextLvl;
	int mExp;
	int mHealth;
	int mMaxHealth;
	int mArmor;
	

};



#endif // !CHARACTER_H
