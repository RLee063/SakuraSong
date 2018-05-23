#pragma once
#include <list>
using namespace std;

class GameObject;
class Hero;
class Enemy;

class BattleManager
{
public:
	BattleManager();
	~BattleManager();
	void addToFriend(GameObject* obj);
	void addToEnemy(GameObject* obj);
	Enemy * getEnemy();
	Hero * getHero();
	void start();
	void end();
	void update();
private:
	bool _is;
	Hero * _hero;
	Enemy * _enemy;
	list<GameObject *> _friendList;
	list<GameObject *> _enemyList;
};