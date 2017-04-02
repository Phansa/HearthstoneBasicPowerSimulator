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

//Draw Function
void processDraw(Class* &hero,int turn, int player)
{
	if(hero->cards_remaining() > 0)
	{
		hero->draw();
		printf("TURN %i: Player %i draws a card: %i cards left in deck.\n", turn, player, hero->cards_remaining());
	}
	else
	{
		hero->draw();
		printf("TURN %i: Player %i attempts to draw a card and takes %i fatigue damage: %i health remaining.\n", turn, player, hero->get_fatigue(), hero->get_health());
	}
}

/*//Processes hero power
void processPower(Class* & hero1, Class* & hero2, int player, int turn)
{
	//Player 1's Power
	if(player == 1)
	{
		printf("TURN %i: Player 1 uses their hero power ", turn);
		hero1->power();
		if (Hunter* t = dynamic_cast<Hunter*>(hero1)) {
			hero2->damage(2);
			printf("to deal 2 damage to the enemy hero.\n");
			if(!hero2->isAlive())
			{
				printf("TURN %i: Player 1 wins!\n", turn);
				game_over = true;
			}
		}
		if(Warlock* t = dynamic_cast<Warlock*>(hero1))
		{
			printf("to draw a card.\n");
			if(!hero1->isAlive())
			{
				printf("TURN %i: Player 1 died to fatigue\n", turn);
				printf("TURN %i: Player 2 wins!\n", turn);
				game_over = true;
			}
		}
		return;
		//printf("\n");
	}
	//Player 2's Power
	else
	{
		printf("TURN %i: Player 2 uses their hero power ", turn);
		hero2->power();
		if (Hunter* t = dynamic_cast<Hunter*>(hero2)) {
			hero1->damage(2);
			printf("to deal 2 damage to the enemy hero.\n");
			if(!hero1->isAlive())
			{
				printf("TURN %i: Player 2 wins!\n", turn);
				game_over = true;
			}
		}
		if(Warlock* t = dynamic_cast<Warlock*>(hero2))
		{
			printf("to draw a card.\n");
			hero2->processDraw();
			if(!hero2->isAlive())
			{
				printf("TURN %i: Player 2 takes %i fatigue damage: %i health remaining.\n", turn, hero2->get_fatigue(), hero2->get_health());
				printf("TURN %i: Player 2 died to fatigue.\n", turn);
				printf("TURN %i: Player 1 wins!\n", turn);
				game_over = true;
			}
		}
		return;
		//printf("\n");
	}
}
*/
void victory(int turn, int player)
{
	if(player == 1)
	{
		printf("TURN %i: Player 1 wins!\n", turn);
	}
	else
	{
		printf("TURN %i: Player 2 wins!\n", turn);
	}
	game_over = true;
}
void processPower(Class* & hero1, Class* &hero2, int turn, int player)
{
	printf("TURN %i: Player %i uses their hero power ", turn, player);
	hero1->power();
	if (Hunter* t = dynamic_cast<Hunter*>(hero1)) {
		hero2->damage(2);
		printf("to deal 2 damage to the enemy hero.\n");
		if(!hero2->isAlive())
		{
			victory(turn, player);
		}
	}
	if(Warlock* t = dynamic_cast<Warlock*>(hero1))
	{
		printf("to draw a card.\n");
		processDraw(hero1, turn, player);
		if(!hero1->isAlive())
		{
			printf("TURN %i: Player %i died to fatigue\n", turn, player);
			victory(turn, player);
		}
	}
	return;
}
//Starts the game simulation
void simulatorProcessing(Class* & hero1, Class* & hero2)
{
	int turn = 0;
	//Initial draw
	for(int i = 0; i < 3; ++i)
	{
		processDraw(hero1, turn, 1);
	}
	for(int i = 0; i < 4; ++i)
	{
		processDraw(hero2, turn, 2);
	}
	++turn;
	while(!game_over)
	{
		//Player 2's turn
		if(turn % 2 == 0)
		{
			printf("TURN %i: Player 2 starts their turn.\n", turn);
			processDraw(hero2, turn, 2);
			if(!hero2->isAlive())
			{
				printf("TURN %i: Player 2 died to fatigue.\n", turn);
				printf("TURN %i: Player 1 wins!\n", turn);
				//game_over = true;
				break;
			}
			processPower(hero2, hero1, turn, 2);
		}
		//Player 1's turn
		else
		{
			//Player cannot use hero power on turn 1
			printf("TURN %i: Player 1 starts their turn.\n", turn);
			processDraw(hero1, turn, 1);
			if(turn != 1)
			{
				processPower(hero1, hero2, turn, 1);
			}
			if(!hero1->isAlive())
			{
				printf("TURN %i: Player 1 died to fatigue.\n", turn);
				printf("TURN %i: Player 2 wins!\n", turn);
				break;
			}
		}
		if(game_over)
		{
			break;
		}
		printf("TURN %i: Player 1 has %i health remaining and %i cards left in deck.\n", turn, hero1->get_health(), hero1->cards_remaining());
		printf("TURN %i: Player 2 has %i health remainig and %i cards left in deck.\n", turn, hero2->get_health(), hero2->cards_remaining());
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

			simulatorProcessing(hero1, hero2);
			printf("Simulator finished...shuting down.\n");
			delete hero1;
			delete hero2;
			hero1 = NULL;
			hero2 = NULL;
		}
	}
	return EXIT_SUCCESS;
}