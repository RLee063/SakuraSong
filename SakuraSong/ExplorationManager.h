#pragma once
#include "ExecutionManager.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "Hero.h"

class DecisionManager;

class ExecutionManager;

class ExplorationManager
{
public:
	ExplorationManager();
	~ExplorationManager();
	MenuManager * getMenuManager();
	DecisionManager * getDecManager();
	ExecutionManager * getExeManager();
	MapManager * getMapManager();
	sf::RenderWindow* getWindow();
	Hero * getHero();
	bool isMoveable(DIRECTION direction);

private:
	sf::RenderWindow* _myWindow;
	Hero * _currentHero;
	MenuManager * _currentMenuManager;
	ExecutionManager * _currentExeManager;
	DecisionManager * _currentDecManager;
	MapManager * _currentMapManager;
};