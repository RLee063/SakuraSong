#include "RoleManager.h"
#include "testInclude.h"
#include "Creator.h"
RoleManager::RoleManager()
{
	_hero = Locator::getCreator()->createHero();
}

RoleManager::~RoleManager()
{
}

Role * RoleManager::getHero()
{
	return _hero;
}

Enemy * RoleManager::getEnemy()
{
	return (Enemy*)_enemy;
}

list<sf::Sprite*> RoleManager::getRenderList()
{
	list<sf::Sprite*> sList;
	sList.push_back(_hero->getSprite());
	return sList;
}

void RoleManager::eraseEnemy()
{
	delete _enemy;
	_enemy = NULL;
}

void RoleManager::setEnemy(GameObject * enemy)
{
	_enemy = enemy;
}
