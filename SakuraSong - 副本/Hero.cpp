#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

Hero::Hero()
{
	for (int i = 0; i < HERO_TEXTURE_NUMBER; i++) {
		string ps1 = "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\Hero";
		string ps2 = to_string(i);
		string ps3 = ".png";
		if (!_myTexture[i].loadFromFile(ps1 + ps2 + ps3)) {
			cout << " error " << endl;
		}
	}
	_mySprite.setTexture(_myTexture[0]);
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

void Hero::setNextTexture()
{
	_textureIndex = (_textureIndex + 1) % (HERO_TEXTURE_NUMBER);
	_mySprite.setTexture(_myTexture[_textureIndex]);
}

DIRECTION* Hero::getDirection()
{
	return &_direction;
}

bool Hero::isMoving()
{
	return _isMoving;
}

void Hero::setMovingState(bool isM)
{
	_isMoving = isM;
}
