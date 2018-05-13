#include "DecisionManager.h"
#include "SFML\Graphics.hpp"
#include "Includes.h"

DecisionManager::DecisionManager(ExplorationManager * expM) 
{
	_expManager = expM;
}


DecisionManager::~DecisionManager()
{
}

void DecisionManager::keyDown(int code) {
	DIRECTION dir = NODIRECTION;
	switch (code)
	{
	case sf::Keyboard::W:
		dir = UP;
		break;
	case sf::Keyboard::S:
		dir = DOWN;
		break;
	case sf::Keyboard::A:
		dir = LEFT;
		break;
	case sf::Keyboard::D:
		dir = RIGHT;
		break;
	default:
		return;
		break;
	}
	if (_expManager->getHero()->isMoving()) {
		return;
	}
	if (dir != NODIRECTION) {
		if (_expManager->isMoveable(dir)) {
			_expManager->getHero()->setMovingState(1);
			_expManager->getExeManager()->add(new ChangeDirection(_expManager->getHero(), &dir));
			_expManager->getExeManager()->add(new HeroMove(_expManager));
		}
	}
}