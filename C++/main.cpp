#include <stdio.h>
#include <string>
#include <iostream>
#ifndef CLASS
#define CLASS
#include "Classes/Class.h"
#endif
#ifndef HUNTER
#define HUNTER
#include "Classes/Hunter.h"
#endif
#ifndef PRIEST
#define PRIEST
#include "Classes/Priest.h"
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
int main()
{
	std::string player1;
	std::string player2;
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
			Warlock a;
			for(int i = 0; i < 32; ++i)
			{
				a.draw();
			}
			printf("Warlock has %i Health left \n", a.get_health());
			printf("%i\n", a.cards_remaining());
			Hunter b;
			printf("%i\n", b.damage(2));
		}
	}
	return EXIT_SUCCESS;
}