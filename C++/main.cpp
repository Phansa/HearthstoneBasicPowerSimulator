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
void test()
{
	printf("Starting tests: \n")
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
			printf("The simulator will now begin: \n");
			hero1 = Creator.produceHero(player1);
			hero2 = Creator.produceHero(player2);
			delete hero1;
			delete hero2;
			hero1 = NULL;
			hero2 = NULL;
		}
	}
	return EXIT_SUCCESS;
}