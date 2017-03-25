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
	character player; //Instantiate player object.
	mob* Monster = 0;  //Initialize pointer to null for the sake of clarity.
	ofstream outData;
	ifstream inData("Data.txt");

	
	int mainInput = 1;  // Main game menu input
	bool gameLoop = true;


	if (player.checkData(inData))	//Checking if data file is empty
	
		player.createClass(); //Function that initializes character creation.

	else
	{
		player.load(inData);
		
	}
	

	while (gameLoop) //Game loop

	{
		system("CLS");
		
		cout << "HEALTH: "<< player.playerHealth() <<" | POSITION: " << "(" << gameMap.getX()  << "," << gameMap.getY() << ")" << endl;

		cout << endl << "What would you like to do? " << endl << endl;

		cout << "1). Move" << endl;
		cout << "2). Detailed Stats" << endl;
		cout << "3). Rest" << endl;
		cout << "4). Exit Game" << endl;

		cin >> mainInput;
	

		switch (mainInput)
		{

		case 1:

			gameMap.move(); 
			Monster = gameMap.getEncounter(); //Once the player finishes moving, gets a random encounter
			
			if (Monster != 0)			//If pointer returned is != 0, proced to battle
			{
				while (true)
				{
					system("cls");
					cout <<endl<< "\t IN COMBAT" << endl << endl;
					cout << " Your Health: "<< player.playerHealth() <<"  |  "<< Monster->mobName() <<"'s Health: "<< Monster->mobHealth() << endl << endl;
					bool Run = player.playerAttack(*Monster); //Player decides whether he runs or fights *MUST FINISH FUNCTION IMPLEMENTATION*

					if (Run)
					{										//If escaped properly, breaks the combat loop
						break;
					}

					if (Monster->nIsDead())					//Checks if monster died when player attacked 
					{
						system("cls");
						cout << "NICE, YOU DEFEATED THE " << Monster->mobName() << endl;
						system("Pause");
						player.experience(*Monster);				//Increase level, victory msg
						break;
					}

					else
						Monster->mobAttack(player);		//If monster survived, attacks *POLISH FUNCTION*

					if (player.mIsDead())				//Checks if last mob's attack killed the player
					{
						system("cls");
						cout << "\t\tYOU DED" << endl;	//Game Over bois.
						player.save(outData);			//Saves players progress.	
						system("pause");
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

		delete Monster; //Deleting monster in the heap.
		Monster = 0; //Returning pointer to null


	}
	
	
  return 0;

}


