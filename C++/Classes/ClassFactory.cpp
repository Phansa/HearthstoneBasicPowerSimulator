#ifndef CLASS
#define CLASS
#include "Class.h"
#endif
#ifndef CLASSFACTORY
#define CLASSFACTORY
#include "ClassFactory.h"
#endif
#ifndef DRUID
#define DRUID
#include "Druid.h"
#endif
#ifndef HUNTER
#define HUNTER
#include "Hunter.h"
#endif
#ifndef PRIEST
#define PRIEST
#include "Priest.h"
#endif
#ifndef WARLOCK
#define WARLOCK
#include "Warlock.h"
#endif
#ifndef WARRIOR
#define WARRIOR
#include "Warrior.h"
#endif
#include <string>

Class* ClassFactory::produceHero(std::string hero_type)
{
	if (hero_type == "druid")
	{
		return new Druid;
	}
	else if(hero_type == "hunter")
	{
		return new Hunter;
	}
	else if(hero_type == "priest")
	{
		return new Priest;
	}
	if(hero_type == "warlock")
	{
		return new Warlock;
	}
	if(hero_type == "warrior")
	{
		return new Warrior;
	}
}
