#pragma once
#include "Includes.h"
class Role;

class RoleHandleImplement {
public:
	RoleHandleImplement(Role * obj);
	virtual void update() = 0;
protected:
	Role * _obj;
};

class RoleIdleHandleImplement:public RoleHandleImplement {
public:
	RoleIdleHandleImplement(Role* obj);
	void update();
};

class RoleStandHandleImplement :public RoleHandleImplement {
public:
	RoleStandHandleImplement(Role * obj);
	void update();
private:
	bool isMoveable(DIRECTION * dir);
	int _time;
};
///////////////////////////////////////////////
class RoleGraphicImplement {
public:
	RoleGraphicImplement(Role * obj);
	virtual void update() = 0;
protected:
	Role * _obj;
};

class RoleMoveGraphicImplement : public RoleGraphicImplement {
public:
	RoleMoveGraphicImplement(Role * obj);
	void update();
private:
	int _count;
	int _time;
};

class RoleStandGraphicImplement :public
	RoleGraphicImplement {
public:
	RoleStandGraphicImplement(Role *obj);
	void update();
private:
};

class RoleBattleGraphicImplement :public RoleGraphicImplement {
public:
	RoleBattleGraphicImplement(Role *obj);
	void update();
};
/////////////////////////////////////////////
class RolePhysicsImplement {
public:
	RolePhysicsImplement(Role * obj);
	virtual void update() = 0;
protected:
	Role * _obj;
};

class RoleMovePhysicsImplement:public RolePhysicsImplement {
public:
	RoleMovePhysicsImplement(Role * obj);
	void update();
private:
	int _count;
	int _time;
};

class RoleIdlePhysicsIplement : public RolePhysicsImplement {
public:
	RoleIdlePhysicsIplement(Role * obj);
	void update();
};

class RoleAttackPhysicsIplement :public
	RolePhysicsImplement {
public:
	RoleAttackPhysicsIplement(Role *obj);
	void update();
private:
	int _count;
	int _time;
};

class RoleInjurePhysicsImplement :public RolePhysicsImplement {
public:
	RoleInjurePhysicsImplement(Role *obj);
	void update();
private:
	int _count;
	int _time; 
};