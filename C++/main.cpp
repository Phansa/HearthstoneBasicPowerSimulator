#include <stdio.h>
#include <string>
#include <iostream>
#ifndef CLASS
#define CLASS
#endif
#include "Classes/Class.h"
#ifndef CLASSFACTORY
#define CLASSFACTORY
#include "Classes/ClassFactory.h"
#endif
#ifndef DRUID
#define DRUID
#include "Classes/Druid.h"
#endif
#ifndef HUNTER
#define HUNTER
#include "Classes/Hunter.h"
#endif
#ifndef MAGE
#define MAGE
#include "Classes/Mage.h"
#endif
#ifndef PALADIN
#define PALADIN
#include "Classes/Paladin.h"
#endif
#ifndef PRIEST
#define PRIEST
#include "Classes/Priest.h"
#endif
#ifndef ROGUE
#define ROGUE
#include "Classes/Rogue.h"
#endif
#ifndef SHAMAN
#define SHAMAN
#include "Classes/Shaman.h"
#endif
#ifndef WARLOCK
#define WARLOCK
#include "Classes/Warlock.h"
#endif
#ifndef WARRIOR
#define WARRIOR
#include "Classes/Warrior.h"
#endif

bool game_over = false;

//Checks if the string is valid and formats it to read for the factory
bool namecheck(std::string &heroname)
{
	for(int i = 0; i < heroname.length(); ++i)
	{
		heroname[i] = tolower(heroname[i]);
	}
	if(heroname != "druid" && heroname != "hunter" && heroname != "mage" && heroname != "paladin" && heroname != 
		"priest" && heroname != "rogue" && heroname != "shaman" && heroname != "warlock" && heroname != "warrior")	
	{
		return false;
	}
	return true;
}

//Processes hero power
void process_power(Class* & hero1, Class* & hero2, int player, int turn)
{
	if(player == 1)
	{
		printf("TURN %i: Player 1 uses their hero power ", turn);
		hero1->power();
		if (Hunter* t = dynamic_cast<Hunter*>(hero1)) {
			hero2->damage(2);
			printf("to deal 2 damage to the enemy hero.\n");
			if(!hero2->isAlive())
			{
				printf("TURN %i: Player 1 wins!\n");
				game_over = true;
			}
			return;
		}
		printf("\n");
	}
	else
	{
		printf("TURN %i: Player 2 uses their hero power ", turn);
		hero1->power();
		if (Hunter* t = dynamic_cast<Hunter*>(hero2)) {
			hero1->damage(2);
			printf("to deal 2 damage to the enemy hero.\n");
			if(!hero1->isAlive())
			{
				printf("TURN %i: Player 2 wins!\n");
				game_over = true;
			}
			return;
		}
		printf("\n");
	}
}

//Starts the game simulation
void simulator_processing(Class* & hero1, Class* & hero2)
{
	int turn = 1;
	//Initial draw
	for(int i = 0; i < 3; ++i)
	{
		hero1->draw();
	}
	for(int i = 0; i < 4; ++i)
	{
		hero2->draw();
	}
	while(!game_over)
	{
		//Player 2's turn
		if(turn % 2 == 0)
		{
			hero2->draw();
			if(!hero2->isAlive())
			{
				printf("Turn %i: Player 2 died to fatigue\n");
				//game_over = true;
				break;
			}
			process_power(hero1, hero2, 2, turn);
		}
		//Player 1's turn
		else
		{
			//Player cannot use hero power on turn 1
			hero1->draw();
			if(turn != 1)
			{
				process_power(hero1, hero2, 1, turn);
			}
		}
		if(game_over)
		{
			break;
		}
		printf("TURN %i: Player 1 has %i health remaining and %i cards left \n", turn, hero1->get_health(), hero1->cards_remaining());
		printf("TURN %i: Player 2 has %i health remainig and %i cards left \n", turn, hero2->get_health(), hero2->cards_remaining());
		++turn;
	}
}

//Testing my factory for each class
void factoryTest()
{
	ClassFactory test_creator;
	Class* testhero;
	printf("Factory Test initializing:\n");

	//Druid factory test
	testhero = test_creator.produceHero("druid");
	if (Druid* t = dynamic_cast<Druid*>(testhero)) {
		printf("I'm a druid!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Hunter factory test
	testhero = test_creator.produceHero("hunter");
	if (Hunter* t = dynamic_cast<Hunter*>(testhero)) {
		printf("I'm a hunter!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Mage factory test
	testhero = test_creator.produceHero("mage");
	if (Mage* t = dynamic_cast<Mage*>(testhero)) {
		printf("I'm a mage!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Paladin factory test
	testhero = test_creator.produceHero("paladin");
	if (Paladin* t = dynamic_cast<Paladin*>(testhero)) {
		printf("I'm a paladin!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Priest factory test
	testhero = test_creator.produceHero("priest");
	if (Priest* t = dynamic_cast<Priest*>(testhero)) {
		printf("I'm a priest!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Rogue factory test
	testhero = test_creator.produceHero("rogue");
	if (Rogue* t = dynamic_cast<Rogue*>(testhero)) {
		printf("I'm a rogue!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Shaman factory test
	testhero = test_creator.produceHero("shaman");
	if (Shaman* t = dynamic_cast<Shaman*>(testhero)) {
		printf("I'm a shaman!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;

	//Warlock factory test
	testhero = test_creator.produceHero("warlock");
	if (Warlock* t = dynamic_cast<Warlock*>(testhero)) {
		printf("I'm a warlock!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;
	//Warrior factory test
	testhero = test_creator.produceHero("warrior");
	if (Warrior* t = dynamic_cast<Warrior*>(testhero)) {
		printf("I'm a warrior!\n");
	}
	else
	{
		printf("FATAL ERROR!!!!!!!\n");
	}
	delete testhero;
	testhero = NULL;
}

//Damage test
void damageTest()
{
	printf("Damage Test initializing:\n");
	Warlock a;
	for(int i = 0; i < 32; ++i)
	{
		a.draw();
	}
	printf("Warlock has %i health left\n", a.get_health());
	printf("Warlock has %i cards left\n", a.cards_remaining());
	Hunter b;
	printf("Hunter has %i health left\n", b.damage(2));
}

//Starting the test suite
void test()
{
	printf("Starting tests~\n");
	factoryTest();
	damageTest();
}

int main()
{
	std::string player1;
	std::string player2;
	Class* hero1 = NULL;
	Class* hero2 = NULL;
	ClassFactory Creator;
	srand(time(NULL));
	test();
	while(true)
	{
		printf("Please enter the names of the two classes you would like to use or type Q to exit: \n");
		std::cin >> player1;
		if( (player1 == "Q") || (player1 == "q"))
		{
			return EXIT_SUCCESS;
		}
		else
		{
			while(!namecheck(player1))
			{
				printf("Invalid hero name: %s\n", player1.c_str());
				printf("Please enter a valid hero name or Q to quit.\n");
				std::cin >> player1;
				if( (player1 == "Q") || (player1 == "q"))
				{
					return EXIT_SUCCESS;
				}
			}
			std::cin >> player2;
			while(!namecheck(player2))
			{
				printf("Invalid hero name: %s\n", player2.c_str());
				printf("Please enter a valid hero name or Q to quit.\n");
				std::cin >> player2;
				if( (player2 == "Q") || (player2 == "q"))
				{
					return EXIT_SUCCESS;
				}
			}
			printf("Your selected classes are %s and %s \n", player1.c_str(), player2.c_str());
			hero1 = Creator.produceHero(player1);
			hero2 = Creator.produceHero(player2);
			printf("The simulator will now begin: \n");
			int i = rand()%2;
/*			if(i == 0)
			{
				printf("HEADS %i\n", i);
			}
			else
			{
				printf("TAILS %i\n", i);
			}*/
			if(i == 1)
			{
				Class* temp = hero1;
				hero1 = hero2;
				hero2 = temp;
				printf("TURN 0: %s is going first\n", player2.c_str());
			}
			else
			{
				printf("TURN 0: %s is going first\n", player1.c_str());
			}

			simulator_processing(hero1, hero2);
			printf("Simulator finished...shuting down.\n");
			delete hero1;
			delete hero2;
			hero1 = NULL;
			hero2 = NULL;
		}
	}
	return EXIT_SUCCESS;
}