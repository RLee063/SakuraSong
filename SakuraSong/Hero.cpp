#include <iostream>
#include <string>
#include "Hero.h"
#include "Locator.h"
#include "MapManager.h"
using namespace std;

Hero::Hero()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < heroTextureNumber; j++) {
			string ps1 = "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\hero\\Hero";
			string ps2 = to_string(i);
			string ps3 = to_string(j);
			string ps4 = ".png";
			_myTexture[i][j].loadFromFile(ps1 + ps2 + ps3 + ps4);

			}
		}
	_mySprite.setTexture(_myTexture[0][0]);
	_mySprite.setPosition(sf::Vector2f(400, 400));
	_textureIndex = 0;
	_isMoving = false;
}

Hero::~Hero()
{

}

sf::Sprite* Hero::getSprite() {
	return &_mySprite;
}

void Hero::setDirection(DIRECTION* dir)
{
	_direction = *dir;
}


DIRECTION* Hero::getDirection()
{
	return &_direction;
}

bool Hero::isMoving()
{
	return _isMoving;
}

bool Hero::isMoveable(DIRECTION * direction)
{
	if (_isMoving == 1) {
		return 0;
	}
	sf::Vector2i* heroPos = Locator::getMapManager()->getHeroPos();
	int ** map = Locator::getMapManager()->getMap();
	switch (*direction)
	{
	case UP:
		if (heroPos->y - 1 < 1) return 0;
		break;
	case DOWN:
		if (heroPos->y + 1 > MAP_HEIGHT) return 0;
		break;
	case LEFT:
		if (heroPos->x - 1 < 1) return 0;
		break;
	case RIGHT:
		if (heroPos->x + 1 > MAP_WIDTH) return 0;
		break;
	default:
		break;
	}
	return 1;
}

void Hero::startMove(DIRECTION * dir)
{
	if (isMoveable(dir)) {
		_isMoving = true;
		setDirection(dir);
//		Locator::getAnimationManager()->add(new heroMoveAnimation());
		_mySprite.setTexture(_myTexture[*dir][_textureIndex]);
		sf::Vector2i *posInMap = Locator::getMapManager()->getHeroPos();
		switch (*dir)
		{
		case UP:
			posInMap->y -= 1;
			break;
		case DOWN:
			posInMap->y += 1;
			break;
		case LEFT:
			posInMap->x -= 1;
			break;
		case RIGHT:
			posInMap->x += 1;
			break;
		default:
			break;
		}
	}
}

void Hero::setMovingState(bool isM)
{
	_isMoving = isM;
}

void Hero::update()
{
	if (_isMoving) {
		_animationCount++;
		if (_animationCount % 100 == 0) {
			//Graphic
			_mySprite.setTexture(_myTexture[_direction][_textureIndex]);
			_textureIndex++;
			//Physics
			switch (_direction)
			{
			case UP:
				_mySprite.move(sf::Vector2f(0, -WALK_LENGTH / 4));
				break;
			case DOWN:
				_mySprite.move(sf::Vector2f(0, WALK_LENGTH / 4));
				break;
			case LEFT:
				_mySprite.move(sf::Vector2f(-WALK_LENGTH / 4, 0));
				break;
			case RIGHT:
				_mySprite.move(sf::Vector2f(WALK_LENGTH / 4, 0));
				break;
			default:
				break;
			}
			if (_textureIndex > heroTextureNumber - 1) {
				_isMoving = 0;
				_textureIndex = 0;
				_animationCount = 0;
			}
		}
	}
	Locator::getWindow()->draw(_mySprite);
}