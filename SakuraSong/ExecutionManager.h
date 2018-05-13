#pragma once
#include <list>

#include "ExplorationManager.h"
using namespace std;

class Executor;

class ExecutionManager
{
public:
	ExecutionManager();
	~ExecutionManager();
	void execute();
	void add(Executor* exe);
private:
	list<Executor*> _executorList;
};



