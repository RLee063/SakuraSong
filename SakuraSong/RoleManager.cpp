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

list<sf::Sprite*> RoleManager::getRenderList()
{
	list<sf::Sprite*> sList;
	sList.push_back(_hero->getSprite());
	return sList;
}
