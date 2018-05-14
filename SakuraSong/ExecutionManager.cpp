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
	for (list<Execution*>::iterator it = _executionsList.begin(); it != _executionsList.end();) {
		if (!(*it)->execute()) {
			delete *it;
			_executionsList.erase(it++);
		}
		else {
			it++;
		}
	}
}

void ExecutionManager::add(Execution * exe) {
	_executionsList.push_back(exe);
}