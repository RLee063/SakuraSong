#pragma once
#include <list>

#include "ExplorationManager.h"
using namespace std;

class Execution;

class ExecutionManager
{
public:
	ExecutionManager();
	~ExecutionManager();
	void execute();
	void add(Execution* exe);
private:
	list<Execution*> _executionsList;
};



