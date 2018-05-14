#include "DecisionManager.h"
#include "SFML\Graphics.hpp"
//#include "Includes.h"

DecisionManager::DecisionManager(ExplorationManager * expM) 
{
	_expManager = expM;
}


DecisionManager::~DecisionManager()
{
}

void DecisionManager::decide()
{
	for (list<Decision*>::iterator it = _decisionsList.begin(); it != _decisionsList.end();) {
		if (!(*it)->decide()) {
			delete *it;
			_decisionsList.erase(it++);
		}
		else {
			it++;
		}
	}
}

void DecisionManager::add(Decision *dec)
{
	_decisionsList.push_back(dec);
}
