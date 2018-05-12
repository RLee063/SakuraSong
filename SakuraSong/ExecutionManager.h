#pragma once
#include <list>
#include "Executor.h"
#include "ExplorationManager.h"
using namespace std;

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



