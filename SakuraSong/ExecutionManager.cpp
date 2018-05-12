#include "ExecutionManager.h"
#include "DecisionManager.h"


ExecutionManager::ExecutionManager()
{
}


ExecutionManager::~ExecutionManager()
{
}

void ExecutionManager::execute() {
	for (list<Executor*>::iterator it = _executorList.begin(); it != _executorList.end();) {
		if (!(*it)->execute()) {
			delete *it;
			_executorList.erase(it++);
		}
		else {
			it++;
		}
	}
}

void ExecutionManager::add(Executor * exe) {
	_executorList.push_back(exe);
}