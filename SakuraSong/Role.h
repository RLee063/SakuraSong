#pragma once
#include "Includes.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"
class Role: public GameObject
{
public:
	Role();
	~Role();
	sf::Sprite* getSprite();

protected:
	sf::Sprite _mySprite;
	int _animationCount;
};


class Hero :public Role
{
public:
	Hero();
	~Hero();
	void update();
	void handleInput();
	bool isMoveable(DIRECTION * direction);
	void startMove(DIRECTION * direction);
	void setDirection(DIRECTION* dir);
	DIRECTION* getDirection();
	void swapStat();
	DIRECTION _direction;
	//========================
	int getHp();
	void attack(GameObject * obj);
	void injured(int agg);
private:
	const static int heroTextureNumber = 4;
	sf::Texture _myTexture[4][heroTextureNumber];
	int _textureIndex;
	bool _isMoving;
	//------------battle---------
	bool _isBattle;
	sf::Texture _battleT;
	int _HP;
	int _attackPower;
};

class Enemy :public Role {
public:
	Enemy();
	void attack(GameObject * obj);
	void injured(int agg);
	void update();
	int getHp();
private:
	int _HP;
	int _attackPower;
	sf::Texture _myT;
};