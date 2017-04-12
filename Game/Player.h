#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include "Creature.h"
#include <string>

class Player : public Creature 
{

public:
	
	Player::Player();
	Player::Player(std::string, std::string,int, int, int, int, int, int, int, int, int);

	void createClass();
	void rest();

	//Saving/Loading data

	void save(std::ofstream&);
	void load(std::ifstream&);
	bool checkData(std::ifstream&);		//Returns true if Data file its empty

	
	bool Attack(Creature*Enemy);	//Overriden function from creature class. Returns true if attempt to run rolls true
	void experience(Monster&mob);
	void levelUp();
	void increaseStats();
	void showStats();
	int playerLvl();

private:

	int mLevel;
	int mExpNextLvl;
	int mExp;
	int mEnemiesDefeated;

};

#endif // !PLAYER_H
