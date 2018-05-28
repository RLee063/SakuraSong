#pragma once

class Role;

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
};

class RoleStandGraphicImplement :public
	RoleGraphicImplement {
public:
	RoleStandGraphicImplement(Role *obj);
	void update();
private:
};


class RolePhysicsImplement {
public:
	RolePhysicsImplement(Role * obj);
	virtual void update() = 0;
protected:
	Role * _Obj;
};

class RoleMovePhysicsImplement {
public:

};

class RoleStandPhysicsImplement : public RolePhysicsImplement {
public:
	RoleStandPhysicsImplement(Role * obj);
	void update();
};