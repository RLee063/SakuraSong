#pragma once

class Role;
class BattleScene;
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

