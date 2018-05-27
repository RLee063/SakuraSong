#pragma once
#include "testInclude.h"
#include <list>
#include "BackGround.h"
using namespace std;

class Scene
{
public:
	Scene();
	~Scene();
	void pushObj(GameObject * obj);
	GameObject * popObj();
	virtual void update() = 0;
protected:
	list<GameObject *> _menuList;
};

class NormalScene :public Scene {
public:
	NormalScene();
	void handleEvent();
	void update();
	void init(char * tPath, char * mapInfoPath, sf::Vector2i* heroPos, Hero * hero);
	MAPINFO** getMapInfo();
	sf::Vector2i * getHeroPos();
	//temp functions
private:
	int _mapLength;
	int _mapWidth;
	MapBackGround * _map;
	sf::Sprite _backS;
	sf::Texture _backT;
	MAPINFO ** _mapInfo;
	GameObject * ** _mapOfObject;
	//temp vars
	sf::Vector2i _heroPos;
	Hero * _hero;
};

class BattleScene :public Scene {
public:
	BattleScene();
	void update();
private:
	Role * _hero;
	Role * _enemy;
	list<GameObject *>_menuList;
};