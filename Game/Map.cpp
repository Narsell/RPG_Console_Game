#include <iostream>
#include "Map.h"
#include "Random.h"
#include "Character.h"

using namespace std;

map::map(){

	mX = 0;
	mY = 0;
}

mob* map::getEncounter()
{
	int dice = Random(0, 10);

	
	if (dice >= 0 && dice <= 5)
	{
		return 0;
	}

	else if (dice == 6)
	{
		mob*monster = new mob("ORC", "Great Sword", 7, 12, 120, 120, 10, 650);
		system("cls");
		cout << "You've encountered an Orc!" << endl;
		cout << "PREPARE FOR BATTLE" << endl;
		system("pause");
		return monster;


	}
	else if (dice == 7)
	{
		mob*monster = new mob("ASSASIN", "Deadly Dagger", 15, 21, 75, 75, 17, 650);
		system("cls");
		cout << "You've encountered an Assasin!" << endl;
		cout << "PREPARE FOR BATTLE" << endl;
		system("pause");
		return monster;

	}
	else if (dice == 8)
	{
		mob*monster = new mob("Alien Droid", "Blaster", 9, 17, 80, 80, 9, 650);
		system("cls");
		cout << "You've encountered an Alien Droid!" << endl;
		cout << "PREPARE FOR BATTLE" << endl;
		system("pause");
		return monster;

	}
	else if (dice == 9)
	{
		mob*monster = new mob("ELF", "Staff", 9, 17, 70, 70, 1, 650);
		system("cls");
		cout << "You've encountered an Elf!" << endl;
		cout << "PREPARE FOR BATTLE" << endl;
		system("pause");
		return monster;

	}
	else if (dice == 10)
	{
		mob*monster = new mob("HUMAN", "Pistol", 2, 14, 90, 90, 5, 650);
		system("cls");
		cout << "You've encountered a Human!" << endl;
		cout << "PREPARE FOR BATTLE" << endl;
		system("pause");
		return monster;

	}
}

int map::getX()
{
	return mY;
}

int map::getY()
{
	return mX;
}

void map::move()
{
	
	int x = 1;
	bool moving = true;
	
	while (moving)
	{
		system("CLS");
		cout << endl << "========================" << endl;
		cout  << "CURRENT POSITION: " << "(" << mX << "," << mY << ")" << endl;
		cout  << "========================" << endl;

		cout << "1). UP" << endl;
		cout << "2). DOWN" << endl;
		cout << "3). RIGHT" << endl;
		cout << "4). LEFT" << endl;
		cout << "5). RETURN" << endl;

		cin >> x;

		switch (x)
		{

		case 1:
			mY++;

			break;
		case 2:
			mY--;
			break;

		case 3:
			mX++;
			break;
		case 4:
			mX--;
			break;
		case 5:
			moving = false;
			break;
		
		}

		


	}

}