#pragma once
#include "Includes.h"
class Scene;
class Role;
class RoleState;
class Terrain;

class Creator
{
public:
	Creator();
	~Creator();
	Scene * createMap1Scene();
	Scene * createBattle1Scene();
	Role * createHero();
	Role * createEnemy();
	Terrain * createTerrain(TERRAIN terType, int x, int y);
	RoleState * createHeroStandState(Role * obj);
	RoleState * createRoleMoveState(Role * obj);
	RoleState * createRoleBattleState(Role * obj);
	RoleState * createRoleAttackState(Role * obj);
	RoleState * createRoleInjuredState(Role * obj);
	RoleState * createRoleStandState(Role * obj);
private:
	Scene * _map1Scene;
	Scene * _battle1Scene;
};

