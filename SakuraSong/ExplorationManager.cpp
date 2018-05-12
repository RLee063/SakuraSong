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

void ExplorationManager::setHero(Hero * h) {
	_currentHero = h;
}

Hero * ExplorationManager::getHero() {
	return _currentHero;
}