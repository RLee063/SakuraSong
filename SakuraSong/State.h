#pragma once
#include "Includes.h"

class Hero;
class RoleGraphicImplement;
class RolePhysicsImplement;
class RoleHandleImplement;
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
	void init(RoleGraphicImplement * gi, RolePhysicsImplement * pi, RoleHandleImplement * hi);
protected:
	RoleGraphicImplement * _graphicIm;
	RolePhysicsImplement * _physicsIm;
	RoleHandleImplement * _handleIm;
	Role * _obj;
};