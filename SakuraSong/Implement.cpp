#include "Implement.h"
#include "testInclude.h"

RoleMoveGraphicImplement::RoleMoveGraphicImplement(Role * obj)
	:RoleGraphicImplement(obj)
{
}

void RoleMoveGraphicImplement::update()
{
}

RoleGraphicImplement::RoleGraphicImplement(Role * obj)
	:RoleGraphicImplement(obj)
{
	_obj = obj;
}

RolePhysicsImplement::RolePhysicsImplement(Role * obj)
{
	_Obj = obj;
}

RoleStandGraphicImplement::RoleStandGraphicImplement(Role * obj)
	:RoleGraphicImplement(obj)
{
}

void RoleStandGraphicImplement::update()
{
	_obj->getSprite()->setTexture(_obj->getStandTexture()[_obj->getDirection]);
}

RoleStandPhysicsImplement::RoleStandPhysicsImplement(Role * obj)
	:RolePhysicsImplement(obj)
{
}

void RoleStandPhysicsImplement::update()
{
}
