#ifndef CLASS
#define CLASS
#include "Class.h"
#endif
#ifndef WARLOCK
#define WARLOCK
#include "Warlock.h"
#endif

void Warlock::power()
{
	health -= 2;
	draw();
}
Warlock::Warlock()
{
	
}