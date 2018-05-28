#pragma once

class Scene;
class Role;
class RoleState;

class Creator
{
public:
	Creator();
	~Creator();
	Scene * createMap1Scene();
	Role * createHero();
	RoleState * createRoleStandState(Role * obj);
private:
	Scene * _map1Scene;
};

