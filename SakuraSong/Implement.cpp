#include "Implement.h"
#include "testInclude.h"

RoleMoveGraphicImplement::RoleMoveGraphicImplement(Role * obj)
	:RoleGraphicImplement(obj)
{
}

void RoleMoveGraphicImplement::update()
{
	if (_time++ % ANIMATION_DELAY != 0) {
		sf::Texture tt = (*_obj->getMoveTexture())[*_obj->getDirection()][_count];
		_obj->getSprite()->setTexture(tt);
		Locator::getWindow()->draw(*_obj->getSprite());
		return;
	}
	sf::Texture tt = (*_obj->getMoveTexture())[*_obj->getDirection()][_count];
	_obj->getSprite()->setTexture(tt);
	_count++;
	Locator::getWindow()->draw(*_obj->getSprite());
	if (_count > 3) {
		((NormalScene *)Locator::getWorld()->getScene())->getHero()->setState(Locator::getCreator()->createHeroStandState(_obj));
		sf::Vector2i* posInMap = ((NormalScene *)Locator::getWorld()->getScene())->getHeroPos();
		switch (*_obj->getDirection())
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

RoleGraphicImplement::RoleGraphicImplement(Role * obj)
{
	_obj = obj;
}

RolePhysicsImplement::RolePhysicsImplement(Role * obj)
{
	_obj = obj;
}

RoleStandGraphicImplement::RoleStandGraphicImplement(Role * obj)
	:RoleGraphicImplement(obj)
{
}

void RoleStandGraphicImplement::update()
{
	sf::Texture ** t = _obj->getStandTexture();
	int index = *_obj->getDirection();
	_obj->getSprite()->setTexture((*t)[index]);
	Locator::getWindow()->draw(*_obj->getSprite());
}

RoleIdlePhysicsIplement::RoleIdlePhysicsIplement(Role * obj)
	:RolePhysicsImplement(obj)
{
}

void RoleIdlePhysicsIplement::update()
{
}

RoleHandleImplement::RoleHandleImplement(Role * obj)
{
	_obj = obj;
}

RoleIdleHandleImplement::RoleIdleHandleImplement(Role * obj)
	:RoleHandleImplement(obj)
{
}

void RoleIdleHandleImplement::update()
{
}

RoleMovePhysicsImplement::RoleMovePhysicsImplement(Role * obj)
	:RolePhysicsImplement(obj)
{
	_obj = obj;
}

void RoleMovePhysicsImplement::update()
{
	if (_time++ % ANIMATION_DELAY != 0) {
		return;
	}
	DIRECTION *dir = _obj->getDirection();
	sf::Sprite * sp = _obj->getSprite();
	switch (*dir)
	{
	case UP:
		sp->move(sf::Vector2f(0, -WALK_LENGTH / 4));
		break;
	case DOWN:
		sp->move(sf::Vector2f(0, WALK_LENGTH / 4));
		break;
	case LEFT:
		sp->move(sf::Vector2f(-WALK_LENGTH / 4, 0));
		break;
	case RIGHT:
		sp->move(sf::Vector2f(WALK_LENGTH / 4, 0));
		break;
	default:
		break;
	}
}

	RoleStandHandleImplement::RoleStandHandleImplement(Role * obj)
		:RoleHandleImplement(obj)
	{
		_obj = obj;
	}

	bool RoleStandHandleImplement::isMoveable(DIRECTION * direction)
	{
		sf::Vector2i* heroPos = ((NormalScene*)Locator::getWorld()->getScene())->getHeroPos();
		Terrain *** map = ((NormalScene*)Locator::getWorld()->getScene())->getMapInfo();
		switch (*direction)
		{
		case UP:
			if (heroPos->y - 1 < 0 || !map[heroPos->x][heroPos->y -1]->isMoveable()) return 0;
			break;
		case DOWN:
			if (heroPos->y + 1 > MAP_HEIGHT - 1 || !map[heroPos->x][heroPos->y + 1]->isMoveable()) return 0;
			break;
		case LEFT:
			if (heroPos->x - 1 < 0 || !map[heroPos->x-1][heroPos->y]->isMoveable()) return 0;
			break;
		case RIGHT:
			if (heroPos->x + 1 > MAP_WIDTH - 1 || !map[heroPos->x][heroPos->y]->isMoveable()) return 0;
			break;
		default:
			break;
		}
		return 1;
	}

	void RoleStandHandleImplement::update()
	{
		if (_time++ < ANIMATION_DELAY) {
			return;
		}
		if (((NormalScene*)Locator::getWorld()->getScene())->isMenuListEmpty()) {
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
				if (isMoveable(&dir)) {
					_obj->setState(Locator::getCreator()->createRoleMoveState(_obj));
				}
			}
		}
	}

	RoleBattleGraphicImplement::RoleBattleGraphicImplement(Role * obj)
		:RoleGraphicImplement(obj)
	{
	}

	void RoleBattleGraphicImplement::update()
	{
		sf::Texture ** t = _obj->getBattleTexture();
		_obj->getSprite()->setTexture((*t)[0]);
		Locator::getWindow()->draw(*_obj->getSprite());;
	}

	RoleAttackPhysicsIplement::RoleAttackPhysicsIplement(Role * obj)
		:RolePhysicsImplement(obj)
	{
	}

	void RoleAttackPhysicsIplement::update()
	{
		if (_time++ % (ANIMATION_DELAY) != 0) {
			return;
		}
		if (_count == 0) {
			_obj->getSprite()->move(sf::Vector2f(10, 0));
			_count++;
			return;
		}
		else if(_count == 7){
			_obj->getSprite()->move(sf::Vector2f(-10, 0));
			_count++;
			_obj->setState(Locator::getCreator()->createRoleBattleState(_obj));
			return;
		}
		else if (_count % 2 == 0) {
			_obj->getSprite()->move(sf::Vector2f(-20, 0));
			_count++;
			return;
		}
		else {
			_obj->getSprite()->move(sf::Vector2f(20, 0));
			_count++;
			return;
		}
	}

	RoleInjurePhysicsImplement::RoleInjurePhysicsImplement(Role * obj):
		RolePhysicsImplement(obj)
	{
	}

	void RoleInjurePhysicsImplement::update()
	{
		if (_time++ % (ANIMATION_DELAY) != 0) {
			return;
		}
		if (_count == 7) {
			_obj->getSprite()->setColor(sf::Color::White);
			_obj->setState(Locator::getCreator()->createRoleBattleState(_obj));
			return;
		}
		else if (_count % 2 == 0) {
			_obj->getSprite()->setColor(sf::Color::Red);
			_count++;
			return;
		}
		else {
			_obj->getSprite()->setColor(sf::Color::White);
			return;
		}
	}
