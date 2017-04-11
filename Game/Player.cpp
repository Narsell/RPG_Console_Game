#include <iostream>
#include <fstream>
#include "Player.h"
#include "Map.h"
#include "Random.h"
#include <cmath>



Player::Player()
	:Creature("Default Name", "Default Weapon", 0, 1, 1, 1, 1), mLevel(1), mExp(0), mExpNextLvl(2)
{
}

Player::Player(std::string Name, std::string weaponName, int rLow, int rHigh, int Health, int maxHealth, int Armor, int Level, int nLevel, int xP)
	: Creature(Name, weaponName, rLow, rHigh, Health, maxHealth, Armor), mLevel(Level), mExp(xP), mExpNextLvl(nLevel)
{
}

void Player::createClass()
{
	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "Welcome to character creation" << std::endl;
	std::cout << "=============================" << std::endl << std::endl;
	
	std::cout << "Type your Nickname: ";
	std::cin >> mName;

	std::cout << std::endl << "Select your class: " << std::endl;
	std::cout << "1. Human Whale" << std::endl << "2. Dank Lord" << std::endl << "3. Pupper" << std::endl;

	int CharNumber = 1;
	std::cin >> CharNumber;

	switch (CharNumber)
	{
	
	case 1: //Selected Human Whale
		std::cout << std::endl << "You've selected Human Whale" << std::endl;
		mLevel = 1;
		mExpNextLvl = 1000;
		mExp = 0;
		creatureWeapon.wName = "Staff";
		creatureWeapon.wRange.Rlow = 1;
		creatureWeapon.wRange.RHigh = 7;
		mHealth = 750;
		mMaxHealth = 750;	
		mArmor = 5;

		break;

	case 2: //Selected Dank Lord
		std::cout << std::endl << "You've selected Dank Lord" << std::endl;
		mLevel = 1;
		mExpNextLvl = 1000;
		mExp = 0;
		creatureWeapon.wName = "Blaster";
		creatureWeapon.wRange.Rlow = 8;
		creatureWeapon.wRange.RHigh = 15;
		mHealth = 470;
		mMaxHealth = 470;	
		mArmor = 2;

		break;

	case 3: //Selected Pupper
		std::cout << std::endl << "You've selected Pupper" << std::endl;
		mLevel = 1;
		mExpNextLvl = 1000;
		mExp = 0;
		creatureWeapon.wName = "God boye";
		creatureWeapon.wRange.Rlow = 17;
		creatureWeapon.wRange.RHigh = 29;
		mHealth = 350;
		mMaxHealth = 350;
		mArmor = 1;

		break;

	}

	std::cout << std::endl << "Welcome to Skamu, " << mName << " enjoy your stay" << std::endl << std::endl;
	system("pause");

}

void Player::showStats()
{
	std::cout << std::endl << "CHARACTER STATS" << std::endl << std::endl;
	
	std::cout << "Nickname: " << mName << std::endl;
	std::cout << "Weapon: " << creatureWeapon.wName << " | Damage Range: from " << creatureWeapon.wRange.Rlow << " to " << creatureWeapon.wRange.RHigh << std::endl;
	std::cout << "Level: " << mLevel << std::endl;
	std::cout << "Current XP: " << mExp << std::endl;
	std::cout << "XP for level " << mLevel + 1 << " : " << mExpNextLvl << std::endl;
	std::cout << "Health: " << mHealth <<"/" << mMaxHealth << std::endl;
	std::cout << "Armor: " << mArmor << std::endl;
	std::cout << "Enemies Encountered: " << Monster::MOB_COUNT << std::endl << std::endl;
	system("pause");

}

int Player::playerLvl()
{
	return mLevel;
}

void Player::rest()
{
	std::cout << "Resting..." << std::endl;
	system("pause");
	mHealth = mMaxHealth;
	std::cout << "Health has been restored to maximum" << std::endl;
	system("pause");
	
}

void Player::save(std::ofstream&File)
{
	File.open("Data.txt");//Creating save file

	File << mName << std::endl;
	File << creatureWeapon.wName << std::endl;
	File << creatureWeapon.wRange.Rlow << std::endl;
	File << creatureWeapon.wRange.RHigh << std::endl;
	File << mLevel << std::endl;
	File << mExp << std::endl;
	File << mExpNextLvl << std::endl;
	File << mMaxHealth << std::endl;
	File << mMaxHealth << std::endl;
	File << mArmor << std::endl;
	File << Monster::MOB_COUNT;

	File.close();
	
}

void Player::load(std::ifstream &File)
{
										//Not reading mName, see checkData implementation (line 171)
	getline(File, creatureWeapon.wName);
	File >> creatureWeapon.wRange.Rlow;
	File >> creatureWeapon.wRange.RHigh;
	File >> mLevel;
	File >> mExp;
	File >> mExpNextLvl;
	File >> mHealth;			//Player will start full health
	File >> mMaxHealth;		
	File >> mArmor;
	File >> Monster::MOB_COUNT;

	File.close();


}

bool Player::checkData(std::ifstream & File)
{
	std::string check;
	getline(File, check);
	mName = check;
	return check.empty();
}

bool Player::Attack(Creature*Enemy)
{
	int input = 1;

	std::cout << "1) Attack" << std::endl;
	std::cout << "2) Attempt escape" << std::endl;

	do {

		std::cin >> input;

	} while (input != 1 && input != 2);

	switch (input)
	{
	case 1:

		Creature::Attack(Enemy); //Calls inherited function
		return false;
		break;

	case 2:

		int dice = Random(1, 4);

		if (dice == 1)
		{
			std::cout << "You successfully escaped" << std::endl;
			system("pause");
			return true;    // Main function will see true so i'll break; there. Otherwise it just keeps on the combat loop
		}
		else
		{
			std::cout << "You miserably failed to escape" << std::endl;
			system("pause");
			return false;

		}
		break;
	}
	
}

void Player::experience(Monster & mob)
{
	system("cls");
	std::cout << "NICE, YOU DEFEATED THE " << mob.Name() << std::endl;
	system("Pause");


	int xpReward = mob.Monster::mXpReward; //Gets the mob's reward for killing it

	mExp += xpReward;
	if (mExp >= mExpNextLvl) //Ask before calling the level up function to minimize computation.
	{
		levelUp();
	}

}

void Player::levelUp()
{
	system("cls");
	std::cout << "\t\tCONGRATULATIONS, YOU HAVE LEVELED UP!" << std::endl << "You're now level " << mLevel + 1 << std::endl;
	system("pause");
	increaseStats();  

}

void Player::increaseStats()
{

	mLevel++;
	mExpNextLvl = pow(mExpNextLvl, 1.1);
	creatureWeapon.wRange.Rlow += Random(1, 3);
	creatureWeapon.wRange.RHigh += Random(1, 3);
	mMaxHealth += Random(50, 65);
	mArmor += Random(1, 2);

	mHealth = mMaxHealth; // Returns Health to new max.

	system("cls");
	std::cout << std::endl << "STATS INCREASED!" << std::endl << std::endl;
	std::cout << "Weapon Range: " << creatureWeapon.wRange.Rlow << ", " << creatureWeapon.wRange.RHigh << std::endl;
	std::cout << "Maximum Health: " << mMaxHealth << std::endl;
	std::cout << "Armor: " << mArmor << std::endl;
	system("pause");


}





