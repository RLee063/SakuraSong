#pragma once
#include "Includes.h"
#include "Role.h"
#include <list>
#include "Locator.h"
using namespace std;

class RoleManager
{
public:
	RoleManager();
	~RoleManager();
	Hero * getHero();
	Enemy * getEnemy();
	list<sf::Sprite*> getRenderList();
	void update();
	void eraseEnemy();
	void setEnemy(GameObject * enemy);
private:
	Hero * _hero;
	GameObject * _enemy;
};

