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
		damage(fatigue);
	}
}

int Class::cards_remaining()
{
	return deck;
}

//Calculates the correct health to subtract if armor is present
int Class::damage(int damage_taken)
{
	int remaining = 0;
	if(armor > 0)
	{
		if(damage_taken - armor >= 0)
		{
			armor -= damage_taken;
		}
		else
		{
			remaining = damage_taken - armor;
			armor = 0;
			health -= remaining;
		}
	}
	else
	{
		health -= damage_taken;
	}
	return health;
}

int Class::get_health()
{
	return health;
}

bool Class::isAlive()
{
	if(health <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}