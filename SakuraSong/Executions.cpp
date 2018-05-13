#include "Executions.h"
#include "ExplorationManager.h"
#define WALK_LENGTH 80

ChangeDirection::ChangeDirection(Hero * hero, DIRECTION * dr)
{
	_hero = hero;
	_dr = *dr;
}

bool ChangeDirection::execute()
{
	_hero->setDirection(&_dr);
	return 0;
}

HeroMove::HeroMove(ExplorationManager * exp)
{
	_timeCount = 0;
	_tIndex = 0;
	_expManager = exp;
}

bool HeroMove::execute()
{
	_timeCount++;
	if (_timeCount % 70 != 0) {
		return 1;
	}
	Hero * hero = _expManager->getHero();
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
