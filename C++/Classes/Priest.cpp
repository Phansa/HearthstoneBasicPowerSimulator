#ifndef CLASS
#define CLASS
#include "Class.h"
#endif
#ifndef PRIEST
#define PRIEST
#include "Priest.h"
#endif

void Priest::power()
{
	if(health <= 28)
	{
		health += 2;
	}
	else
	{
		health = 30;
	}
}
