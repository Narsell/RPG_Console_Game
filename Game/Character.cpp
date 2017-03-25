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
	playerWeapon.wRange.Rlow = 0;
	playerWeapon.wRange.RHigh = 0;
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
	playerWeapon.wRange.Rlow = Rlow;
	playerWeapon.wRange.RHigh = rHigh;
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
		playerWeapon.wName = "Staff";
		playerWeapon.wRange.Rlow = 1;
		playerWeapon.wRange.RHigh = 7;
		mHealth = 750;
		mMaxHealth = 750;	
		mArmor = 5;

		break;

	case 2: //Selected Dank Lord
		cout << endl << "You've selected Dank Lord" << endl;
		mLevel = 1;
		mExpNextLvl = 1000;
		mExp = 0;
		playerWeapon.wName = "Blaster";
		playerWeapon.wRange.Rlow = 8;
		playerWeapon.wRange.RHigh = 15;
		mHealth = 470;
		mMaxHealth = 470;	
		mArmor = 2;

		break;

	case 3: //Selected Pupper
		cout << endl << "You've selected Pupper" << endl;
		mLevel = 1;
		mExpNextLvl = 1000;
		mExp = 0;
		playerWeapon.wName = "God boye";
		playerWeapon.wRange.Rlow = 17;
		playerWeapon.wRange.RHigh = 29;
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
	cout << "Weapon: " << playerWeapon.wName << " | Damage Range: from " << playerWeapon.wRange.Rlow << " to " << playerWeapon.wRange.RHigh << endl;
	cout << "Level: " << mLevel << endl;
	cout << "Current XP: " << mExp << endl;
	cout << "XP for level " << mLevel + 1 << " : " << mExpNextLvl << endl;
	cout << "Health: " << mHealth <<"/" << mMaxHealth << endl;
	cout << "Armor: " << mArmor << endl;
	cout << "Enemies Encountered: " << mob::GetMobCount() << endl << endl;
	system("pause");

}

int character::playerHealth()
{
	return mHealth;
}

int character::playerArmor()
{
	return mArmor;
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
	File << playerWeapon.wName << endl;
	File << playerWeapon.wRange.Rlow << endl;
	File << playerWeapon.wRange.RHigh << endl;
	File << mLevel << endl;
	File << mExp << endl;
	File << mExpNextLvl << endl;
	File << mMaxHealth << endl;
	File << mMaxHealth << endl;
	File << mArmor << endl;

	File.close();
	
}

void character::load(std::ifstream &File)
{
										//Not reading mName, see checkData implementation (line 171)
	getline(File, playerWeapon.wName);
	File >> playerWeapon.wRange.Rlow;
	File >> playerWeapon.wRange.RHigh;
	File >> mLevel;
	File >> mExp;
	File >> mExpNextLvl;
	File >> mHealth;			//Player will start full health
	File >> mMaxHealth;		
	File >> mArmor;

	File.close();


}

bool character::checkData(std::ifstream & File)
{
	std::string check;
	getline(File, check);
	mName = check;
	return check.empty();
}

//COMBAT IMPLEMETATIONS:

bool character::mIsDead()
{

	return (mHealth <= 0);

}


void character::mTakeDamage(int dmg)
{

	mHealth -= dmg;

}

bool character::playerAttack(mob&mob)
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
	
		
			int dmg, realDmg;
			dmg = Random(playerWeapon.wRange.Rlow, playerWeapon.wRange.RHigh);
			realDmg = dmg - mob.mobArmor();
			mob.nTakeDamage(realDmg);

			cout << "You attack the " << mob.mobName() << " for a total of " << realDmg << " damage ( " << mob.mobArmor() << " absorbed)" << endl;
			system("pause");

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
	int xpReward = mob.Reward(); //Gets the mob's reward for killing it

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
	playerWeapon.wRange.Rlow += Random(1, 5);
	playerWeapon.wRange.RHigh += Random(1, 5);
	mMaxHealth += Random(50, 85);
	mArmor += Random(1, 3);

	mHealth = mMaxHealth; // Returns Health to new max.

	system("cls");
	cout << endl << "STATS INCREASED!" << endl << endl;
	cout << "Weapon Range: " << playerWeapon.wRange.Rlow << ", " << playerWeapon.wRange.RHigh << endl;
	cout << "Maximum Health: " << mMaxHealth << endl;
	cout << "Armor: " << mArmor << endl;
	system("pause");


}





