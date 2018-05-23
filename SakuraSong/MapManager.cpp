#include "MapManager.h"
#include "Locator.h"
#include "Role.h"
#include "MenuManager.h"
#include "Menu.h"
#include "RoleManager.h"
MapManager::MapManager()
{
	_map1Tex.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\picture\\map1.png");
	_battle1T.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\background\\battle1.png");
	_backGroundS.setTexture(_map1Tex);
	_backGroundS.setPosition(sf::Vector2f(0, 0));
	memset(_map, 0, MAP_HEIGHT*MAP_WIDTH*4);
	memset(_mapO, 0, MAP_HEIGHT*MAP_WIDTH*4);
	//-------------
	_mapO[8][8] = new Enemy();
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

int** MapManager::getMap() {
	return (int**)_map;
}

sf::Sprite * MapManager::getMapSprite()
{
	return &_backGroundS;
}

void MapManager::update()
{
	if (_mapO[_heroPos.x][_heroPos.y] != NULL) {
		Locator::getMapManager()->swatchBack();
		Locator::getMenuManager()->add(new BattleMainMenu());
		Locator::getRoleManager()->getHero()->swapStat();
		Locator::getRoleManager()->setEnemy(_mapO[_heroPos.x][_heroPos.y]);
		_mapO[_heroPos.x][_heroPos.y] = NULL;
	}
	Locator::getWindow()->draw(_backGroundS);
}

void MapManager::swatchBack()
{
	_backGroundS.setTexture(_battle1T);
}
