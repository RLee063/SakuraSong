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
	DIRECTION* getDirection();
	void setDirection(DIRECTION* dir);
	bool isMoving();
protected:

	sf::Sprite _mySprite;
	DIRECTION _direction;
	bool _isMoving;
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

private:
	const static int heroTextureNumber = 4;
	sf::Texture _myTexture[4][heroTextureNumber];
	int _textureIndex;
};

class Villager :public Role {

};