#pragma once
#include "ExecutionManager.h"
#include "ExplorationManager.h"
#include "Executions.h"

class DecisionManager
{
public:
	DecisionManager(ExplorationManager * expM);
	~DecisionManager();
	void keyDown(int code);
private:
	ExplorationManager * _expManager;
};

