#pragma once
#include "Includes.h"
class Role;
class BattleScene;
class NormalScene;
class Command
{
public:
	Command();
	~Command();
	virtual bool excute() = 0;
protected:
	int _time;
};

class HeroAttackCommand :public Command {
public:
	HeroAttackCommand();
	bool excute();
private:
	Role * _hero;
	Role * _enemy;
	BattleScene * _scene;
};

class ViewMoveCommand :public Command {
public:
	ViewMoveCommand( NormalScene * s);
	bool excute();
private:
	int _count;
	sf::RenderWindow * _window;
	NormalScene * _scene;
};
