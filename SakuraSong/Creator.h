#pragma once
//#includ "Includes.h"
#include "SFML\Graphics.hpp"
#include "Typedef.h"
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
	Role * createRole(ROLE rType);
	Terrain * createTerrain(TERRAIN terType, int x, int y);
	RoleState * createHeroStandState(Role * obj);
	RoleState * createRoleMoveState(Role * obj);
	RoleState * createRoleBattleState(Role * obj);
	RoleState * createRoleAttackState(Role * obj);
	RoleState * createRoleInjuredState(Role * obj);
	RoleState * createRoleStandState(Role * obj);
	RoleState * createNpcStandState(Role * obj);
	sf::Sprite * createBuild(BUILD buildType);
private:
	Scene * _map1Scene;
};
