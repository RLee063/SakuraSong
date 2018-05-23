#include "State.h"
#include "testInclude.h"

State::State()
{
}


State::~State()
{
}

HeroStandState::HeroStandState(Hero * obj)
{
	for (int i = 0; i < 4; i++) {
		string ps1 = "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\hero\\Hero";
		string ps2 = to_string(i);
		string ps3 = to_string(0);
		string ps4 = ".png";
		_texture[i].loadFromFile(ps1 + ps2 + ps3 + ps4);
	}
	DIRECTION * dir = obj->getDirection();
	obj->getSprite()->setTexture(_texture[*dir]);
	_obj = obj;
}

State* HeroStandState::handleInput()
{
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
			_obj->setDirection(&dir);
			return new HeroMoveState(_obj);
		}
	}
	return NULL;
}

State * HeroStandState::update()
{
	State * tState = handleInput();
	if (tState == NULL) {
		return this;
	}
	else {
		return tState;
	}
}

HeroMoveState::HeroMoveState(Hero * obj)
{
	_obj = obj;
	int index = *_obj->getDirection();
	for (int i = 0; i < 4; i++) {
		string ps1 = "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\hero\\Hero";
		string ps2 = to_string(index);
		string ps3 = to_string(i);
		string ps4 = ".png";
		_texture[i].loadFromFile(ps1 + ps2 + ps3 + ps4);
	}
	count = 0;
	_dir = _obj->getDirection();
}

State * HeroMoveState::update()
{
	_obj->getSprite()->setTexture(_texture[count]);
	sf::Sprite* _mySprite = _obj->getSprite();
	switch (*_dir)
	{
	case UP:
		_mySprite->move(sf::Vector2f(0, -WALK_LENGTH / 4));
		break;
	case DOWN:
		_mySprite->move(sf::Vector2f(0, WALK_LENGTH / 4));
		break;
	case LEFT:
		_mySprite->move(sf::Vector2f(-WALK_LENGTH / 4, 0));
		break;
	case RIGHT:
		_mySprite->move(sf::Vector2f(WALK_LENGTH / 4, 0));
		break;
	default:
		break;
	}
	count++;
	if (count > heroTextureNumber - 1) {
		return new HeroStandState(_obj);
	}
	else {
		return this;
	}
}

HeroBattleState::HeroBattleState(Hero * obj)
{
	_texture.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\battle\\hero.png");
	_obj = obj;
	_obj->getSprite()->setTexture(_texture);
	_obj->getSprite()->setPosition(sf::Vector2f(100,300));
}

State * HeroBattleState::update()
{
	return this;
}
