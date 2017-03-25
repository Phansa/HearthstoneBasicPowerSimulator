#include <stdio.h>
#include <string>
#include <iostream>
#ifndef CLASS
#define CLASS
#include "Classes/Class.h"
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
			break;
		}
		else
		{
			std::cin >> player2;
			printf("Your selected classes are %s and %s \n", player1.c_str(), player2.c_str());
			printf("The simulator will now begin: \n");
			Warlock a;
			a.draw();
			printf("%i\n", a.cards_remaining());
		}
	}
}