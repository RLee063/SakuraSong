#include "ExecutionManager.h"
#include "DecisionManager.h"
#include "Executions.h"

ExecutionManager::ExecutionManager()
{
}

ExecutionManager::~ExecutionManager()
{
}

void ExecutionManager::execute() {
	for (list<Execution*>::iterator it = _executorList.begin(); it != _executorList.end();) {
		if (!(*it)->execute()) {
			delete *it;
			_executorList.erase(it++);
		}
		else {
			it++;
		}
	}
}

void ExecutionManager::add(Execution * exe) {
	_executorList.push_back(exe);
}