#pragma once
#include "Includes.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class RoleState;
class Menu;
class Role: public GameObject
{
public:
	Role(int hp, int agg);
	~Role();
	sf::Sprite* getSprite();
	sf::Texture*** getMoveTexture();
	sf::Texture** getattackTexture();
	sf::Texture** getStandTexture();
	sf::Texture** getBattleTexture();
	void setDirection(DIRECTION* dir);
	void setState(RoleState * rs);
	void setPosition(sf::Vector2i pos);
	void addHp(int hp);
	void addAttackP(int ap);
	void pushDialog(Menu* m);
	list<Menu*> getDialogList();
	DIRECTION* getDirection();
	int getHp();
	void attack(Role * obj);
	void injured(int agg);
	void update();
	bool isDied();
	//
protected:
	sf::Sprite _mySprite;
	sf::Texture* _standTexture;
	sf::Texture* _battleTexture;
	sf::Texture** _moveTexture;
	sf::Texture* _attackTexture;
	RoleState * _state;
	DIRECTION _direction;
	sf::Vector2i _position;
	int _hp;
	int _attackPower;
	bool _isDied;
	list<Menu*> _dialogList;
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