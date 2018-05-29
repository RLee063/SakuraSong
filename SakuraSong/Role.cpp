#include "Role.h"
#include <iostream>
#include <string>
#include "Role.h"
#include "Locator.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "Control.h"
#include "testInclude.h"
using namespace std;

Role::Role(int hp, int agg)
{
	_hp = hp;
	_attackPower = agg;
}

Role::~Role()
{
}

sf::Sprite* Role::getSprite() {
	return &_mySprite;
}

sf::Texture *** Role::getMoveTexture()
{
	return &_moveTexture;
}

sf::Texture ** Role::getattackTexture()
{
	return &_attackTexture;
}

sf::Texture ** Role::getStandTexture()
{
	return &_standTexture;
}

sf::Texture ** Role::getBattleTexture()
{
	return &_battleTexture;
}

void Role::setDirection(DIRECTION * dir)
{
	_direction = *dir;
}

void Role::setState(RoleState * rs)
{
	_state = rs;
}

void Role::addHp(int hp)
{
	_hp += hp;
}

void Role::addAttackP(int ap)
{
	_attackPower += ap;
}

DIRECTION * Role::getDirection()
{
	return &_direction;
}

int Role::getHp()
{
	return _hp;
}

void Role::attack(Role * obj)
{
	this->setState((Locator::getCreator()->createRoleAttackState(this)));
	obj->injured(this->_attackPower);
}

void Role::injured(int agg)
{
	this->setState((Locator::getCreator()->createRoleInjuredState(this)));
	this->_hp -= agg;
	if (_hp < 0) {
		_isDied = 1;
	}
}

void Role::update()
{
	_state->update();
}

bool Role::isDied()
{
	return _isDied;
}
