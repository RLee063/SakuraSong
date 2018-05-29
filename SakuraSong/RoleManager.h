#pragma once
#include "Includes.h"
#include "Role.h"
#include <list>
#include "Locator.h"
using namespace std;

class Role;
class Enemy;


class RoleManager
{
public:
	RoleManager();
	~RoleManager();
	Role * getHero();
	Enemy * getEnemy();
	list<sf::Sprite*> getRenderList();
	void eraseEnemy();
	void setEnemy(GameObject * enemy);
private:
	Role * _hero;
	GameObject * _enemy;
};

