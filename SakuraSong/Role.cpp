#include <iostream>
#include <string>
#include "Includes.h"
using namespace std;

Role::Role(int hp, int agg, ROLETYPE type)
{
	_type = type;
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

sf::Texture ** Role::getBeBattledTexture()
{
	return &_beBattledTexture;
}

sf::Texture ** Role::getInBattleTexture()
{
	return &_inBattleTexture;
}

void Role::setDirection(DIRECTION * dir)
{
	_direction = *dir;
}

void Role::setState(RoleState * rs)
{
	_state = rs;
}

void Role::setPosition(sf::Vector2i pos)
{
	_position = pos;
	_mySprite.setPosition(sf::Vector2f(float(UNIT_LENGTH*pos.y), (float)UNIT_LENGTH*pos.x));
}

void Role::setTalkState(bool isTalking)
{
	_isTalking = isTalking;
}

void Role::addHp(int hp)
{
	_hp += hp;
}

void Role::addAttackP(int ap)
{
	_attackPower += ap;
}

void Role::pushDialog(Menu*m)
{
	_dialogList.push_back(m);
}

list<Menu*> Role::getDialogList()
{
	return _dialogList;
}

DIRECTION * Role::getDirection()
{
	return &_direction;
}

ROLETYPE Role::getType()
{
	return _type;
}

int Role::getHp()
{
	return _hp;
}

sf::Vector2i * Role::getPosition()
{
	return &_position;
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

bool Role::isTalking()
{
	return _isTalking;
}

void Role::setInBattleTexture(bool isFriend)
{
	if (isFriend) {
		_inBattleTexture = _battleTexture;
	}
	else {
		_inBattleTexture = _beBattledTexture;
	}
}
