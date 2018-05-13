#include "MapManager.h"

MapManager::MapManager()
{
	_map1Tex.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\picture\\map1.png");
	_map1Sprite.setTexture(_map1Tex);
	_map1Sprite.setPosition(sf::Vector2f(0, 0));
	memset(_map, 0, MAP_HEIGHT*MAP_WIDTH);
	_heroPos.x = 6;
	_heroPos.y = 6;
}

MapManager::~MapManager()
{
}

POSITION* MapManager::getHeroPos() {
	return &_heroPos;
}

int** MapManager::getMap() {
	return (int**)_map;
}

sf::Sprite * MapManager::getMapSprite()
{
	return &_map1Sprite;
}
