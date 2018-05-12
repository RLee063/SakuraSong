#include <iostream>
#include "Hero.h"
using namespace std;

Hero::Hero()
{
	if (!_myTexture[0].loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\Hero.png")) {
		cout << " error " << endl;
	}
	_mySprite.setTexture(_myTexture[0]);
	_mySprite.setPosition(sf::Vector2f(12, 12));
}

Hero::~Hero()
{
}

sf::Sprite* Hero::getSprite() {
	return &_mySprite;
}