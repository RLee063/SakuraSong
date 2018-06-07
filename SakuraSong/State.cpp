#include "State.h"
#include "Includes.h"

State::State()
{
}


State::~State()
{
}

RoleState::RoleState(Role * obj)
{
	_obj = obj;
}

void RoleState::update()
{
	_graphicIm->update();
	_physicsIm->update();
	_handleIm->update();
}

void RoleState::init(RoleGraphicImplement * gi, RolePhysicsImplement * pi, RoleHandleImplement * hi)
{
	_handleIm = hi;
	_graphicIm = gi;
	_physicsIm = pi;
}
