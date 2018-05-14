#include "Decisions.h"
#include "ExplorationManager.h"
#include "Executions.h"
extern ExplorationManager * myExpManager;

Decision::Decision(ExplorationManager * expM)
{
	_expManager = expM;
}

Decision::~Decision()
{
}

KeyDown::KeyDown(int code, ExplorationManager * expM):
	Decision(expM)
{
	_code = code;
}

bool KeyDown::decide()
{
	if (_expManager->getMenuManager()->getCurrentMenu() == NULL) {
		DIRECTION dir = NODIRECTION;
		switch (_code)
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
		case sf::Keyboard::K:
			_expManager->getExeManager()->add(new OpenMainMenu(_expManager));
			return 0;
			break;
		default:
			return 0;
			break;
		}
		if (_expManager->getRoleManager()->getHero()->isMoving()) {
			return 0;
		}
		if (dir != NODIRECTION) {
			if (_expManager->isMoveable(dir)) {
				_expManager->getRoleManager()->getHero()->setMovingState(1);
				_expManager->getExeManager()->add(new ChangeDirection(&dir, _expManager));
				_expManager->getExeManager()->add(new HeroMove(_expManager));
			}
		}
		return 0;
	}
	else {
		switch (_code)
		{
		case sf::Keyboard::K:
			_expManager->getExeManager()->add(new LeftMainMenu(_expManager));
			break;
		}
		return 0;
	}
}
