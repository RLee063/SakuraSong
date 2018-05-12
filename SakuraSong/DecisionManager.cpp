#include "DecisionManager.h"
#include "SFML\Graphics.hpp"

DecisionManager::DecisionManager(ExplorationManager * expM) 
{
	_expManager = expM;
}


DecisionManager::~DecisionManager()
{
}

void DecisionManager::keyDown(int code) {
	switch (code)
	{
	case sf::Keyboard::W:
		_expManager->getExeManager()->add(new HeroMoveUp(_expManager->getHero()));
		break;
	default:
		break;
	}
}