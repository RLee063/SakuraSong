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

Role::Role()
{
}

Role::~Role()
{
}

sf::Sprite* Role::getSprite() {
	return _mySprite;
}

sf::Texture ** Role::getMoveTexture()
{
	return _moveTexture;
}

sf::Texture * Role::getattackTexture()
{
	return _attackTexture;
}

sf::Texture * Role::getStandTexture()
{
	return  _standTexture;
}

sf::Texture * Role::getBattleTexture()
{
	return _battleTexture;
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

void Hero::setDirection(DIRECTION* dir)
{
	_direction = *dir;
}

DIRECTION* Hero::getDirection()
{
	return &_direction;
}

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
	_mySprite.setPosition(sf::Vector2f((float)WALK_LENGTH * 6, (float)WALK_LENGTH * 6));
	_textureIndex = 0;
	_isMoving = false;
	_isBattle = false;
	//////////////////////////
	_battleT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\battle\\hero.png");
	////
	_HP = 200;
	_attackPower = 33;
}

Hero::~Hero()
{

}

bool Hero::isMoveable(DIRECTION * direction)
{
	sf::Vector2i* heroPos = Locator::getMapManager()->getHeroPos();
	int ** map = Locator::getMapManager()->getMapInfo();
	switch (*direction)
	{
	case UP:
		if (heroPos->y - 1 < 0) return 0;
		break;
	case DOWN:
		if (heroPos->y + 1 > MAP_HEIGHT-1) return 0;
		break;
	case LEFT:
		if (heroPos->x - 1 < 0) return 0;
		break;
	case RIGHT:
		if (heroPos->x + 1 > MAP_WIDTH-1) return 0;
		break;
	default:
		break;
	}
	return 1;
}

void Hero::startMove(DIRECTION * dir)
{
	_mySprite.setTexture(_myTexture[*dir][_textureIndex]);
	if (isMoveable(dir)) {
		_isMoving = true;
		setDirection(dir);
	}
}

void Hero::swapStat()
{
	if (!_isBattle) {
		_isBattle = true;
		_mySprite.setTexture(_battleT);
		_mySprite.setPosition(sf::Vector2f(100,300));
	}
	else {
		_isBattle = false;
		_mySprite.setTexture(_myTexture[_direction][0]);
		sf::Vector2i* pos = Locator::getMapManager()->getHeroPos();
		_mySprite.setPosition(sf::Vector2f((float)WALK_LENGTH*(pos->x), (float)WALK_LENGTH*(pos->y)));
	}
}

int Hero::getHp()
{
	return _HP;
}

void Hero::attack(GameObject * obj)
{
	((Enemy*)obj)->injured(_attackPower);
}

void Hero::injured(int agg)
{
	_HP -= agg;
}

void Hero::update()
{
	handleInput();
	if (_isMoving) {
		_animationCount++;
		if (_animationCount % ANIMATION_DELAY == 0) {
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
				sf::Vector2i *posInMap = Locator::getMapManager()->getHeroPos();
				switch (_direction)
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
	}
	Locator::getWindow()->draw(_mySprite);
}

void Hero::handleInput()
{
	if (_isMoving || _isBattle) {
		return;
	}
	if (Locator::getMenuManager()->getCurrentMenu() == NULL) {
		DIRECTION dir = NODIRECTION;
		Control * control = Locator::getControl();
		if (control->ifPressedKey(sf::Keyboard::W)) {
			dir = UP;
		}
		if (control->ifPressedKey(sf::Keyboard::S)) {
			dir = DOWN;
		}
		if (control->ifPressedKey(sf::Keyboard::A)) {
			dir = LEFT;
		}
		if (control->ifPressedKey(sf::Keyboard::D)) {
			dir = RIGHT;
		}
		if (dir != NODIRECTION) {
			startMove(&dir);
		}
	}
}

Enemy::Enemy()
{
	_HP = 100;
	_attackPower = 20;
	_myT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\battle\\xiyi.png");
	_mySprite.setPosition(sf::Vector2f(700, 300));
	_mySprite.setTexture(_myT);
}

void Enemy::attack(GameObject * obj)
{
	((Hero*)obj)->injured(_attackPower);
}

void Enemy::injured(int agg)
{
	_HP -= agg;
}

void Enemy::update()
{
	if (_isVisible) {
		Locator::getWindow()->draw(_mySprite);
	}
	cout << _HP << endl;
}

int Enemy::getHp()
{
	return _HP;
}

void Role::update()
{
	_state->update();
}
