#include <iostream>
#include <fstream>
#include "Character.h"
#include "Map.h"
#include "Random.h"
#include <cmath>


using namespace std;

character::character() //Default constructor 
{
	mName = "DefaultName";
	creatureWeapon.wRange.Rlow = 0;
	creatureWeapon.wRange.RHigh = 0;
	mLevel = 0;
	mExpNextLvl = 0;
	mHealth = 0;
	mMaxHealth = 0;
	mArmor = 0;
	mExp = 0;

	
}

character::character(string Name, string pWeapon, int Rlow, int rHigh, int lvl, int nlvl, int xp, int hp ,int mhp, int armor) //Custom constructor
{
	mName = Name;
	creatureWeapon.wRange.Rlow = Rlow;
	creatureWeapon.wRange.RHigh = rHigh;
	mLevel = lvl;
	mExpNextLvl = nlvl;
	mExp = xp;
	mHealth = hp;
	mMaxHealth = mhp;
	mArmor = armor;
}


void character::createClass()
{
	cout << endl << "=============================" << endl;
	cout << "Welcome to character creation" << endl;
	cout << "=============================" << endl << endl;
	
	cout << "Type your Nickname: "; 
	cin >> mName;

	cout << endl << "Select your class: " << endl;
	cout << "1. Human Whale" << endl << "2. Dank Lord" << endl << "3. Pupper" << endl;

	int CharNumber = 1;
	cin >> CharNumber;

	switch (CharNumber)
	{
	
	case 1: //Selected Human Whale
		cout << endl << "You've selected Human Whale" <<endl;
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
		cout << endl << "You've selected Dank Lord" << endl;
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
		cout << endl << "You've selected Pupper" << endl;
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

	cout << endl << "Welcome to Skamu, " << mName << " enjoy your stay" << endl << endl;
	system("pause");

}

void character::showStats()
{
	cout << endl << "CHARACTER STATS" << endl << endl;
	
	cout << "Nickname: " << mName << endl;
	cout << "Weapon: " << creatureWeapon.wName << " | Damage Range: from " << creatureWeapon.wRange.Rlow << " to " << creatureWeapon.wRange.RHigh << endl;
	cout << "Level: " << mLevel << endl;
	cout << "Current XP: " << mExp << endl;
	cout << "XP for level " << mLevel + 1 << " : " << mExpNextLvl << endl;
	cout << "Health: " << mHealth <<"/" << mMaxHealth << endl;
	cout << "Armor: " << mArmor << endl;
	cout << "Enemies Encountered: " << mob::MOB_COUNT << endl << endl;
	system("pause");

}


int character::playerLvl()
{
	return mLevel;
}


void character::rest()
{
	cout << "Resting..." << endl;
	system("pause");
	mHealth = mMaxHealth;
	cout << "Health has been restored to maximum" << endl;
	system("pause");
	
}

void character::save(std::ofstream&File)
{
	File.open("Data.txt");//Creating save file

	File << mName << endl; 
	File << creatureWeapon.wName << endl;
	File << creatureWeapon.wRange.Rlow << endl;
	File << creatureWeapon.wRange.RHigh << endl;
	File << mLevel << endl;
	File << mExp << endl;
	File << mExpNextLvl << endl;
	File << mMaxHealth << endl;
	File << mMaxHealth << endl;
	File << mArmor << endl;
	File << mob::MOB_COUNT;

	File.close();
	
}

void character::load(std::ifstream &File)
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
	File >> mob::MOB_COUNT;

	File.close();


}

bool character::checkData(std::ifstream & File)
{
	std::string check;
	getline(File, check);
	mName = check;
	return check.empty();
}




bool character::Attack(Creature*Enemy)
{
	int input = 1;

	cout << "1) Attack" << endl;
	cout << "2) Attempt escape" << endl;

	do {

		cin >> input;

	} while (input != 1 && input != 2);

	switch (input)
	{
	case 1:

		Creature::Attack(Enemy); //Calls inherited function
		return false;

	case 2:

		int dice = Random(1, 4);

		if (dice == 1)
		{
			cout << "You successfully escaped" << endl;
			system("pause");
			return true;    // Main function will see true so i'll break; there. Otherwise it just keeps on the combat loop
		}
		else
		{
			cout << "You miserably failed to escape" << endl;
			system("pause");
			return false;

		}

	}
	
}

void character::experience(mob & mob)
{
	int xpReward = mob.mob::xpReward; //Gets the mob's reward for killing it

	mExp += xpReward;
	if (mExp >= mExpNextLvl) //Ask before calling the level up function to minimize computation.
	{
		levelUp();
	}

}

void character::levelUp()
{
	system("cls");
	cout << "\t\tCONGRATULATIONS, YOU HAVE LEVELED UP!" << endl << "You're now level " << mLevel + 1 << endl;
	system("pause");
	increaseStats();  

}

void character::increaseStats()
{

	mLevel++;
	mExpNextLvl = pow(mExpNextLvl, 1.1);
	creatureWeapon.wRange.Rlow += Random(1, 5);
	creatureWeapon.wRange.RHigh += Random(1, 5);
	mMaxHealth += Random(50, 85);
	mArmor += Random(1, 3);

	mHealth = mMaxHealth; // Returns Health to new max.

	system("cls");
	cout << endl << "STATS INCREASED!" << endl << endl;
	cout << "Weapon Range: " << creatureWeapon.wRange.Rlow << ", " << creatureWeapon.wRange.RHigh << endl;
	cout << "Maximum Health: " << mMaxHealth << endl;
	cout << "Armor: " << mArmor << endl;
	system("pause");


}





