#include "Includes.h"

Terrain::Terrain(bool isMab, sf::Texture * t, int x, int y)
{
	_isMoveable = isMab;
	_mySprite.setTexture(*t);
	_mySprite.setPosition(sf::Vector2f((float)y, (float)x));
	_build = NULL;
	_npc = NULL;
	_enemy = NULL;
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

bool Terrain::hasNpc()
{
	if (_npc != NULL) {
		return 1;
	}
	else {
		return 0;
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

void Terrain::killEnemy()
{
	_enemy = NULL;
}

void Terrain::update()
{
	Locator::getWindow()->draw(_mySprite);
	if (_build != NULL) {
		Locator::getWindow()->draw(*_build);
	}
}

void Terrain::update2()
{
	if (_npc != NULL) {
		_npc->update();
	}
}

void Terrain::setBuild(sf::Sprite * s, bool moveable)
{
	_build = s;
	if (_build != NULL) {
		_build->setPosition(_mySprite.getPosition());
		_isMoveable = moveable;
	}
}

void Terrain::setMoveable(bool is)
{
	_isMoveable = is;
}

Role * Terrain::getEnemy()
{
	return _enemy;
}

Role * Terrain::getNpc()
{
	return _npc;
}
