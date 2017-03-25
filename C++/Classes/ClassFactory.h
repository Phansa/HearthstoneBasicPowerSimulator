#ifndef CLASS
#define CLASS
#include "Class.h"
#endif
#include <string>
class ClassFactory
{
	public:
		Class* produceHero(std::string hero_type);
};