#pragma once
#include "Hero.h"
#include <SFML\Graphics.hpp>
#include "Explorations.h"
#include "ExecutionManager.h"
#include "Includes.h"


class ExplorationManager;

class Executor
{
public:
	Executor() {};
	~Executor() {};
	virtual bool execute() = 0;
};

class HeroMove : public Executor {
public:
	HeroMove(ExplorationManager* exp);
	bool execute();
private:
	int _tIndex;
	int _timeCount;
	ExplorationManager * _expManager;
};

class ChangeDirection :public Executor {
public:
	ChangeDirection(Hero * hero, DIRECTION* dr);
	bool execute();
private:
	DIRECTION _dr;
	Hero * _hero;
};