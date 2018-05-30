#pragma once
#include "testInclude.h"
#include <list>
#include "BackGround.h"
using namespace std;

class Command;
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
	sf::Vector2i * getMapSize();
	sf::Vector2i * getLeftUpPoint();
	Role* getHero();
	bool isMenuListEmpty();
	sf::View* getView();
	//	bool isBlockMoveable(int x, int y);
	//temp functions
private:
	bool _isViewMoveable();

	sf::Vector2i _mapSize;
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
	sf::View _view;
	DIRECTION _viewDirection;
	bool _isViewMoving;

	friend class ViewMoveCommand;
};

class BattleScene :public Scene {
public:
	BattleScene(BackGround *, Menu * mainMenu);
	void init(Role* hero, Role * enemy);
	void update();
	Role* getHero();
	Role* getEnemy();
	void handleEvent();
private:
	Role * _hero;
	Role * _enemy;
	//list<Role*>_enemyList;
	BackGround * _backG;
	Menu* _mainMenu;
	bool _ended;
};