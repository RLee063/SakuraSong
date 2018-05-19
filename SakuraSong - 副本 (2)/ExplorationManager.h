#pragma once
#include "ExecutionManager.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "RoleManager.h"
#include "RenderManager.h"

class RenderManager;

class DecisionManager;

class ExecutionManager;

class ExplorationManager
{
public:
	ExplorationManager();
	~ExplorationManager();
	RenderManager * getRenderManager();
	MenuManager * getMenuManager();
	DecisionManager * getDecManager();
	ExecutionManager * getExeManager();
	MapManager * getMapManager();
	RoleManager * getRoleManager();

	sf::RenderWindow* getWindow();
	bool isMoveable(DIRECTION direction);
	bool isButtonBoxMoveable(DIRECTION direction);

private:
	sf::RenderWindow* _myWindow;
	MenuManager * _currentMenuManager;
	ExecutionManager * _currentExeManager;
	DecisionManager * _currentDecManager;
	MapManager * _currentMapManager;
	RoleManager * _currentRoleManager;
	RenderManager * _currentRenderManager;
};