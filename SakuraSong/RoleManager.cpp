#include "RoleManager.h"
#include "ExplorationManager.h"


RoleManager::RoleManager(ExplorationManager * expM)
{
	_expM = expM;
	_hero = new Hero();
}

RoleManager::~RoleManager()
{
}

Hero * RoleManager::getHero()
{
	return _hero;
}
