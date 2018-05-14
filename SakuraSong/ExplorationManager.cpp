#include "ExplorationManager.h"
#include "DecisionManager.h"
ExplorationManager::ExplorationManager()
{
	_currentExeManager = new ExecutionManager();
	_currentDecManager = new DecisionManager(this);
	_currentMapManager = new MapManager();
	_currentMenuManager = new MenuManager();
	_currentRoleManager = new RoleManager(this);
	_myWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");

}

ExplorationManager::~ExplorationManager()
{
}

MenuManager * ExplorationManager::getMenuManager()
{
	return _currentMenuManager;
}

DecisionManager * ExplorationManager::getDecManager() {
	return _currentDecManager;
}

ExecutionManager * ExplorationManager::getExeManager() {
	return _currentExeManager;
}

MapManager * ExplorationManager::getMapManager()
{
	return _currentMapManager;
}

RoleManager * ExplorationManager::getRoleManager()
{
	return _currentRoleManager;
}

sf::RenderWindow * ExplorationManager::getWindow()
{
	return _myWindow;
}

bool ExplorationManager::isMoveable(DIRECTION direction)
{
	POSITION* heroPos = _currentMapManager->getHeroPos();
	int ** map = _currentMapManager->getMap();
	switch (direction)
	{
	case UP:
		if (heroPos->y - 1 < 1) return 0;
		break;
	case DOWN:
		if (heroPos->y + 1 > MAP_HEIGHT) return 0;
		break;
	case LEFT:
		if (heroPos->x - 1 < 1) return 0;
		break;
	case RIGHT:
		if (heroPos->x + 1 > MAP_WIDTH) return 0;
		break;
	default:
		break;
	}
	return 1;
}

