#include "ExplorationManager.h"

ExplorationManager::ExplorationManager()
{
}

ExplorationManager::~ExplorationManager()
{
}

void ExplorationManager::setDecManager(DecisionManager * decM) {
	_currentDecManager = decM;
}

DecisionManager * ExplorationManager::getDecManager() {
	return _currentDecManager;
}

void ExplorationManager::setExeManager(ExecutionManager * exeM) {
	_currentExeManager = exeM;
}

ExecutionManager * ExplorationManager::getExeManager() {
	return _currentExeManager;
}

void ExplorationManager::setMapManager(MapManager * mapM)
{
	_currentMapManager = mapM;
}

MapManager * ExplorationManager::getMapManager()
{
	return _currentMapManager;
}

void ExplorationManager::setHero(Hero * h) {
	_currentHero = h;
}

Hero * ExplorationManager::getHero() {
	return _currentHero;
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

