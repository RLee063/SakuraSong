#pragma once
#include "Includes.h"
#include "Hero.h"
#include <list>
using namespace std;

class ExplorationManager;

class RoleManager
{
public:
	RoleManager(ExplorationManager * expM);
	~RoleManager();
	Hero * getHero();
	list<sf::Sprite*> getRenderList();
private:
	Hero * _hero;
	ExplorationManager * _expM;
};

