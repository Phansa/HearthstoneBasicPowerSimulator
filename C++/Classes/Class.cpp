#ifndef CLASS
#define CLASS
#include "Class.h"
#endif
void Class::draw()
{
	if(deck > 0)
	{
		deck -=1;
	}
	else
	{
		fatigue += 1;
		//Calculates the correct health to subtract if armor is present
		int remaining = 0;
		if(armor > 0)
		{
			if(fatigue - armor >= 0)
			{
				armor -= fatigue;
			}
			else
			{
				remaining = fatigue - armor;
				armor = 0;
				health -= remaining;
			}
		}
		else
		{
			health -= fatigue;
		}
	}
}
int Class::cards_remaining()
{
	return deck;
}