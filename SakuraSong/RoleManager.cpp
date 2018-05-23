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

void RoleManager::update()
{
	if (_enemy != NULL) {
		_enemy->update();
	}
	_hero->update();
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
