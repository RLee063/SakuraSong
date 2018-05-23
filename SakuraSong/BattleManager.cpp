#include "testInclude.h"

BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
}

void BattleManager::addToFriend(GameObject * obj)
{
	_hero = (Hero*)obj;
	_friendList.push_back(obj);
}

void BattleManager::addToEnemy(GameObject * obj)
{
	_enemy = (Enemy*)obj;
	_friendList.push_back(obj);
}

Enemy * BattleManager::getEnemy()
{
	return _enemy;
}

Hero * BattleManager::getHero()
{
	return _hero;
}

void BattleManager::start()
{
	Locator::getMapManager()->swatchBack();
	Locator::getMenuManager()->add(new BattleMainMenu());
	Locator::getRoleManager()->getHero()->swapStat();
	_is = 1;
}

void BattleManager::end()
{
	_hero = NULL;
	_enemy = NULL;
	_friendList.clear();
	_enemyList.clear();
	_is = 0;
	Locator::getMapManager()->swatchBack();
	Locator::getMenuManager()->leftMenu();
	Locator::getRoleManager()->getHero()->swapStat();
	Locator::getRoleManager()->setEnemy(NULL);
}

void BattleManager::update()
{
	if (_is == 0) {
		return;
	}
	if (_hero->getHp() < 0) {
		end();
		return;
	}
	if (_enemy->getHp() < 0) {
		end();
		return;
	}
}
