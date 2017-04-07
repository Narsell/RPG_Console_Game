
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Monster.h"
#include "Random.h"
#include <ctime>
#include <fstream>


int main()
{
	srand(time(0));

	map gameMap;
	Player player;
	Monster* Monster = 0;  //Initialize pointer to null for the sake of clarity.

	std::ofstream outData;
	std::ifstream inData("Data.txt");	//saving/loading objects

	if (player.checkData(inData))	//Checking if data file is empty, returns true if empty
		player.createClass();		//Function that initializes character creation.
	else
		player.load(inData);
		
	
	bool gameLoop = true;
	while (gameLoop) 

	{
		system("CLS");

		std::cout << "HEALTH: " << player.Health() << " | POSITION: " << "(" << gameMap.getX() << "," << gameMap.getY() << ")" << " | LEVEL: " << player.playerLvl() << std::endl;

		std::cout << std::endl << "What would you like to do? " << std::endl << std::endl;

		std::cout << "1). Move" << std::endl;
		std::cout << "2). Detailed Stats" << std::endl;
		std::cout << "3). Rest" << std::endl;
		std::cout << "4). Exit Game" << std::endl;

		int mainInput = 1;
		std::cin >> mainInput;
	
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
					std::cout << std::endl << "\t IN COMBAT" << std::endl << std::endl;
					std::cout << " Your Health: " << player.Health() << "  |  " << Monster->Name() << "'s Health: " << Monster->Health() << std::endl << std::endl;
					bool Run = player.Attack(Monster);		//Player decides whether he runs or fights 

					if (Run)
					{										//If escaped properly, breaks the combat loop. 
						break;						
					}

					if (Monster->IsDead())					//Checks if monster died when player attacked 
					{
						system("cls");
						std::cout << "NICE, YOU DEFEATED THE " << Monster->Name() << std::endl;
						system("Pause");
						player.experience(*Monster);				//Increase experience , victory msg
						break;
					}

					else
						Monster->Attack(&player);		//If monster survived, attacks 

					if (player.IsDead())				//Checks if last mob's attack killed the player
					{
						system("cls");
						std::cout << "\t\tYOU DED" << std::endl;
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


