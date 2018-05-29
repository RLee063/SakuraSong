#include "Terrain.h"
#include "testInclude.h"


Terrain::Terrain(bool isMab, sf::Texture * t, int x, int y)
{
	_isMoveable = isMab;
	_mySprite.setTexture(*t);
	_mySprite.setPosition(sf::Vector2f((float)x, (float)y));
}

Terrain::~Terrain()
{
}

bool Terrain::isMoveable()
{
	if (!_isMoveable) {
		return 0;
	}
	else if (_npc != NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

bool Terrain::isHided()
{
	if (_enemy == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

void Terrain::hideEnemy(Role * obj)
{
	_enemy = obj;
}

void Terrain::npcEnter(Role * obj)
{
	_npc = obj;
}

void Terrain::npcLeft()
{
	_npc = NULL;
}

void Terrain::update()
{
	Locator::getWindow()->draw(_mySprite);
}

Role * Terrain::getEnemy()
{
	return _enemy;
}
