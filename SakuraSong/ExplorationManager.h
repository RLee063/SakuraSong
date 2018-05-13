#pragma once
#include "ExecutionManager.h"
#include "MapManager.h"
#include "Hero.h"

class DecisionManager;

class ExecutionManager;

class ExplorationManager
{
public:
	ExplorationManager();
	~ExplorationManager();
	void setDecManager(DecisionManager * decM);
	DecisionManager * getDecManager();
	void setExeManager(ExecutionManager * exeM);
	ExecutionManager * getExeManager();
	void setMapManager(MapManager * mapM);
	MapManager * getMapManager();
	void setHero(Hero * h);
	Hero * getHero();
	bool isMoveable(DIRECTION direction);

private:
	Hero * _currentHero;
	ExecutionManager * _currentExeManager;
	DecisionManager * _currentDecManager;
	MapManager * _currentMapManager;
};