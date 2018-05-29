#pragma once
#include "testInclude.h"
#include <list>
#include "BackGround.h"
using namespace std;

class Terrain;

class Scene
{
public:
	Scene();
	~Scene();
	virtual void init() {};
	virtual void pushMenu(Menu * obj);
	virtual Menu * popMenu();
	virtual void update() = 0;
	virtual Menu* getCurrentMenu();
	virtual void addCommand(Command * cm);
protected:
	list<Menu *> _menuList;
	list<Command *> _commandList;
};

class NormalScene :public Scene {
public:
	NormalScene(MapBackGround * backG, char * mapInfoPath, sf::Vector2i* heroPos, Role * hero, Menu * mainMenu);
	void handleEvent();
	void update();
	void init();
	Terrain*** getMapInfo();
	sf::Vector2i * getHeroPos();
	Role* getHero();
	bool isMenuListEmpty();
	bool isBlockMoveable(int x, int y);

	//temp functions
private:
	int _mapLength;
	int _mapWidth;
	sf::Vector2i _leftUpPoint;
	MapBackGround * _mapG;
	sf::Sprite _backS;
	sf::Texture _backT;
	Terrain* ** _mapInfo;
	Role* ** _mapOfObject;
	//temp vars
	sf::Vector2i _heroPos;
	Role * _hero;
	Menu * _mainMenu;
};

class BattleScene :public Scene {
public:
	BattleScene(BackGround *, Menu * mainMenu);
	void init(Role* hero, Role * enemy);
	void update();
	Role* getHero();
	Role* getEnemy();
private:
	Role * _hero;
	Role * _enemy;
	//list<Role*>_enemyList;
	BackGround * _backG;
	Menu* _mainMenu;
};