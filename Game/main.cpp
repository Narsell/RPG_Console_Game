// Classes test.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Character.h"
#include "Map.h"
#include "mob.h"
#include "Random.h"
#include <ctime>
#include <fstream>
using namespace std;



int main()
{
	srand(time(0));

	map gameMap;
	character player;
	mob* Monster = 0;  //Initialize pointer to null for the sake of clarity.

	ofstream outData;
	ifstream inData("Data.txt");	//saving/loading objects

	if (player.checkData(inData))	//Checking if data file is empty
		player.createClass(); //Function that initializes character creation.
	else
		player.load(inData);
		
	
	bool gameLoop = true;
	while (gameLoop) 

	{
		system("CLS");

		cout << "HEALTH: " << player.Health() << " | POSITION: " << "(" << gameMap.getX() << "," << gameMap.getY() << ")" << " | LEVEL: " << player.playerLvl() << endl;

		cout << endl << "What would you like to do? " << endl << endl;

		cout << "1). Move" << endl;
		cout << "2). Detailed Stats" << endl;
		cout << "3). Rest" << endl;
		cout << "4). Exit Game" << endl;

		int mainInput = 1;
		cin >> mainInput;
	
		switch (mainInput)
		{

		case 1:

			gameMap.move();
			Monster = gameMap.getEncounter(); //Once the player finishes moving, gets a random encounter

			if (Monster != 0)	//If pointer returned is != 0, proced to battle
			{

				while (true)
				{
					system("cls");
					cout << endl << "\t IN COMBAT" << endl << endl;
					cout << " Your Health: " << player.Health() << "  |  " << Monster->Name() << "'s Health: " << Monster->Health() << endl << endl;
					bool Run = player.Attack(Monster); //Player decides whether he runs or fights 

					if (Run)
					{										//If escaped properly, breaks the combat loop. 
						break;						//Can only return true, otherwise main will 'think' player died.
					}

					if (Monster->IsDead())					//Checks if monster died when player attacked 
					{
						system("cls");
						cout << "NICE, YOU DEFEATED THE " << Monster->Name() << endl;
						system("Pause");
						player.experience(*Monster);				//Increase level, victory msg
						break;
					}

					else
						Monster->Attack(&player);		//If monster survived, attacks 

					if (player.IsDead())				//Checks if last mob's attack killed the player
					{
						system("cls");
						cout << "\t\tYOU DED" << endl;	//Game Over bois.
						system("pause");
						player.save(outData);			//Saves players progress.	
						gameLoop = false;
						break;

					}

				}

			}

			break;

		case 2:

			player.showStats();
			break;

		case 3:

			player.rest();
			break;

		case 4:
			
			player.save(outData); //saves player's data
			gameLoop = false;

		}

	}

	delete Monster; //Deleting monster in the heap.
	Monster = 0; //Returning pointer to null
	
  return 0;

}


