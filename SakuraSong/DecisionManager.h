#pragma once
#include "ExecutionManager.h"
#include "ExplorationManager.h"
#include "Executions.h"
#include "decisions.h"
#include "Includes.h"

class DecisionManager
{
public:
	DecisionManager(ExplorationManager * expM);
	~DecisionManager();
	void decide();
	void add(Decision* dec);

private:
	ExplorationManager * _expManager;
	list<Decision*> _decisionsList;
};

