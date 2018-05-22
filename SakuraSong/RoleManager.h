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
	list<sf::Sprite*> getRenderList();
	void update();
private:
	Hero * _hero;
};

