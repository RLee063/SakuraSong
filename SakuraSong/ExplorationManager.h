#pragma once
#include "ExecutionManager.h"
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
	void setHero(Hero * h);
	Hero * getHero();

private:
	Hero * _currentHero;
	ExecutionManager * _currentExeManager;
	DecisionManager * _currentDecManager;
};