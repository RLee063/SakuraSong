#include "MapManager.h"
#include "Locator.h"
#include "Role.h"
#include "MenuManager.h"
#include "Menu.h"
#include "RoleManager.h"
#include "BattleManager.h"
MapManager::MapManager()
{
	_map1Tex.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\picture\\map1.png");
	_battle1T.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\background\\battle1.png");
	_backGroundS.setTexture(_map1Tex);
	_backGroundS.setPosition(sf::Vector2f(0, 0));
	memset(_map, 0, MAP_HEIGHT*MAP_WIDTH*4);
	memset(_mapO, 0, MAP_HEIGHT*MAP_WIDTH*4);
	//-------------
	for (int i = 0; i < 20; i++) {
		int x = rand() % 9;
		int y = rand() % 9;
		_mapO[x][y] = new Enemy();
	}
	//-------------
	_heroPos.x = 6;
	_heroPos.y = 6;
}

MapManager::~MapManager()
{

}

sf::Vector2i* MapManager::getHeroPos() {
	return &_heroPos;
}

int** MapManager::getMapInfo() {
	return (int**)_map;
}

sf::Sprite * MapManager::getMapSprite()
{
	return &_backGroundS;
}

void MapManager::update()
{
	if (_mapO[_heroPos.x][_heroPos.y] != NULL) {
		Locator::getRoleManager()->setEnemy(_mapO[_heroPos.x][_heroPos.y]);
		Locator::getBattleManager()->addToFriend(Locator::getRoleManager()->getHero());
		Locator::getBattleManager()->addToEnemy(_mapO[_heroPos.x][_heroPos.y]);
		Locator::getBattleManager()->start();
		_mapO[_heroPos.x][_heroPos.y] = NULL;
	}
	Locator::getWindow()->draw(_backGroundS);
}

void MapManager::swatchBack()
{
	if (_backGroundS.getTexture() == &_map1Tex) {
		_backGroundS.setTexture(_battle1T);
	}
	else {
		_backGroundS.setTexture(_map1Tex);
	}
		
}
