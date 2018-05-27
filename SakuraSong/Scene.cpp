#include "Scene.h"
#include "testInclude.h"
#include "Includes.h"
#include "Typedef.h"
Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::pushObj(GameObject * obj)
{
	_menuList.push_back(obj);
}

GameObject * Scene::popObj()
{
	GameObject * obj = _menuList.back();
	_menuList.pop_back();
	return obj;
}

NormalScene::NormalScene()
{
}

void NormalScene::handleEvent()
{
}

void NormalScene::update()
{
	handleEvent();
	_map->update();
	_hero->update();
	for (auto i : _menuList) {
		i->update();
	}
}

void NormalScene::init(char * tPath, char * mapInfoPath, sf::Vector2i* heroPos, Hero * hero)
{
	ifstream fi;
	fi.open(mapInfoPath);
	fi >> _mapLength;
	fi >> _mapWidth;
	for (int i = 0; i < _mapLength; i++) {
		for (int j = 0; j < _mapWidth; j++) {
			fi >> ((int **)_mapInfo)[i][j];
		}
	}
	_map = new MapBackGround(tPath);
	//_backT.loadFromFile(tPath);
	//_backS.setTexture(_backT);
	_heroPos = *heroPos;
	_hero = hero;
	hero->getSprite()->setPosition(sf::Vector2f(float(UNIT_LENGTH*heroPos->x), (float)UNIT_LENGTH*heroPos->y));
}

MAPINFO ** NormalScene::getMapInfo()
{
	return _mapInfo;
}

sf::Vector2i * NormalScene::getHeroPos()
{
	return &_heroPos;
}
