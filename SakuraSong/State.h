#pragma once
#include "Includes.h"

class Hero;
class RoleGraphicImplement;
class RolePhysicsImplement;
class Role;

class State
{
public:
	State();
	~State();
private:
	virtual State* update() = 0;
};

class RoleState {
public:
	RoleState(Role * obj);
	virtual void  update();
	void init(RoleGraphicImplement * gi, RolePhysicsImplement * pi);
protected:
	RoleGraphicImplement * _graphicIm;
	RolePhysicsImplement * _physicsIm;
	Role * _obj;
};

























class HeroStandState :public State {
public:
	HeroStandState(Hero * obj);
	State* handleInput();
	State* update();
private:
	sf::Texture _texture[4];
	Hero* _obj;
};

class HeroMoveState :public State {
public:
	HeroMoveState(Hero* obj);
	State* update();
private:
	const static int heroTextureNumber = 4;
	int count;
	sf::Texture _texture[4];
	Hero* _obj;
	DIRECTION* _dir;
};

class HeroBattleState :public State {
public:
	HeroBattleState(Hero *obj);
	State* update();
private:
	sf::Texture _texture;
	Hero* _obj;
};

class HeroAttackState :public State {
public:
	HeroAttackState(Hero *obj);
	State* update();
};

class HeroInjuredState :public State {
public:
	HeroInjuredState(Hero *obj);
	State* update();
};
