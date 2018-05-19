#include "Executions.h"
#include "ExplorationManager.h"
#define WALK_LENGTH 80

ChangeDirection::ChangeDirection(DIRECTION *dir,ExplorationManager* expM)
	:Execution(expM)
{
	_hero = expM->getRoleManager()->getHero();
	_dr = *dir;
}

bool ChangeDirection::execute()
{
	_hero->setDirection(&_dr);
	return 0;
}

HeroMove::HeroMove(ExplorationManager * exp):
Execution(exp)
{
	_timeCount = 0;
	_tIndex = 0;
}

bool HeroMove::execute()
{
	_timeCount++;
	if (_timeCount % 70 != 0) {
		return 1;
	}
	Hero * hero = _expManager->getRoleManager()->getHero();
	DIRECTION* dir = hero->getDirection();
	sf::Sprite * mS = hero->getSprite();
	int **map = _expManager->getMapManager()->getMap();
	POSITION* heroPos = _expManager->getMapManager()->getHeroPos();
	//hero->setMovingState(1);
	//
	int index = 0;
	//
	hero->setNextTexture();
	_tIndex += 1;
	switch (*dir)
	{
	case UP:
		if (_tIndex == 1)
			heroPos->y -= 1;
		mS->move(sf::Vector2f(0, -WALK_LENGTH/4));
		break;
	case DOWN:
		if (_tIndex == 1)
			heroPos->y += 1;
		mS->move(sf::Vector2f(0, WALK_LENGTH/4));
		break;
	case LEFT:
		if (_tIndex == 1)
			heroPos->x -= 1;
		mS->move(sf::Vector2f(-WALK_LENGTH/4, 0));
		break;
	case RIGHT:
		if (_tIndex == 1)
			heroPos->x += 1;
		mS->move(sf::Vector2f(WALK_LENGTH/4, 0));
		break;
	default:
		break;
	}
	if (_tIndex < 4) {
		return 1;
	}
	else {
		hero->setMovingState(0);
		return 0;
	}
}

OpenMainMenu::OpenMainMenu(ExplorationManager * expM):
Execution(expM)
{}

bool OpenMainMenu::execute()
{
	_expManager->getMenuManager()->switchToMainMenu();
	return 0;
}

Execution::Execution(ExplorationManager* expM)
{
	_expManager = expM;
}

LeftMainMenu::LeftMainMenu(ExplorationManager * exp):
	Execution(exp)
{
}

bool LeftMainMenu::execute()
{
	_expManager->getMenuManager()->leftMainMenu();
	return 0;
}

ButtonBoxMove::ButtonBoxMove(ExplorationManager * exp, DIRECTION dir)
	:Execution(exp)
{
	_dir = dir;
}

bool ButtonBoxMove::execute()
{
	sf::Sprite * buttonBoxS = _expManager->getMenuManager()->getCurrentMenu()->getButtonBoxS();
	Button *** buttonArr = _expManager->getMenuManager()->getCurrentMenu()->getButtonArr();
	sf::Vector2i* buttonIndex = _expManager->getMenuManager()->getCurrentMenu()->getButtonIndex();
	switch (_dir)
	{
	case UP:
		buttonBoxS->setPosition(buttonArr[buttonIndex->x-1][buttonIndex->y]->getSprite()->getPosition());
		buttonIndex->x -= 1;
		break;
	case DOWN:
		buttonBoxS->setPosition(buttonArr[buttonIndex->x+1][buttonIndex->y]->getSprite()->getPosition());
		buttonIndex->x += 1;
		break;
	case LEFT:
		buttonBoxS->setPosition(buttonArr[buttonIndex->x][buttonIndex->y-1]->getSprite()->getPosition());
		buttonIndex->y -= 1;
		break;
	case RIGHT:
		buttonBoxS->setPosition(buttonArr[buttonIndex->x][buttonIndex->y+1]->getSprite()->getPosition());
		buttonIndex->y += 1;
		break;
	default:
		break;
	}
	return 0;
}
