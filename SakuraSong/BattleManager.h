#pragma once
#include <list>
using namespace std;

class GameObject;

class BattleManager
{
public:
	BattleManager();
	~BattleManager();
	void start();
	void end();
	void update();
private:
	list<GameObject *> _friendList;
	list<GameObject *> _enemyList;
};