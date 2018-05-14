#pragma once
#include "Hero.h"
#include <SFML\Graphics.hpp>
#include "Explorations.h"
#include "ExecutionManager.h"
#include "Includes.h"


class ExplorationManager;

class Execution
{
public:
	Execution(ExplorationManager* expM);
	~Execution() {};
	virtual bool execute() = 0;
protected:
	ExplorationManager * _expManager;
};

class HeroMove : public Execution {
public:
	HeroMove(ExplorationManager* expM);
	bool execute();
private:
	int _tIndex;
	int _timeCount;
};

class ChangeDirection :public Execution {
public:
	ChangeDirection(DIRECTION *dir, ExplorationManager* expM);
	bool execute();
private:
	DIRECTION _dr;
	Hero * _hero;
};

class OpenMainMenu : public Execution {
public:
	OpenMainMenu(ExplorationManager* exp);
	bool execute();
private:
};

class LeftMainMenu :public Execution {
public:
	LeftMainMenu(ExplorationManager* exp);
	bool execute();
};