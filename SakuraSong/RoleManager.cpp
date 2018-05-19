#include "RoleManager.h"

RoleManager::RoleManager()
{
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

void RoleManager::update()
{
	_hero->update();
}
