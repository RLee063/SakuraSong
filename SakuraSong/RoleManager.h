#pragma once
#include "Includes.h"
#include "Hero.h"

class ExplorationManager;

class RoleManager
{
public:
	RoleManager(ExplorationManager * expM);
	~RoleManager();
	Hero * getHero();
private:
	Hero * _hero;
	ExplorationManager * _expM;
};

