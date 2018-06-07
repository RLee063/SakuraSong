#pragma once
#include "SFML\Graphics.hpp"
#include "Typedef.h"
#include <list>

using namespace std;

class MapBackGround;
class BackGround;
class Command;
class Terrain;
class Menu;
class Role;

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
	NormalScene(char * mapInfoPath, sf::Vector2i* heroPos, Role * hero, Menu * mainMenu);
	void handleEvent();
	void update();
	void init();
	Terrain*** getMapInfo();
	Terrain* getTerrain(int x, int y);
	sf::Vector2i * getHeroPos();
	sf::Vector2i * getMapSize();
	sf::Vector2i * getLeftUpPoint();
	sf::View * getOriginView();
	Role* getHero();
	bool isMenuListEmpty();
	bool isBlockMoveable(int x, int y);
	sf::View* getView();
	void npcEnter(int x, int y, Role * role);
	void npcLeft(int x, int y);
	void setHeroPos(sf::Vector2i p);
	void setEnemyPos(sf::Vector2i p);
	sf::Vector2i * getEnemyPos();
private:
	void _updateView();
	sf::Vector2i _mapSize;
	sf::Vector2i _leftUpPoint;
	Terrain* ** _mapInfo;
	sf::Vector2i _heroPos;
	sf::Vector2i _enemyPos;
	Role * _hero;
	Menu * _mainMenu;
	sf::View _view;
	sf::View _originView;
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