#pragma once
#include "Includes.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"
class Hero:public GameObject
{
public:
	Hero();
	~Hero();
	sf::Sprite* getSprite();
	void setDirection(DIRECTION* dir);
	DIRECTION* getDirection();
	bool isMoving();
	bool isMoveable(DIRECTION * direction);
	void startMove(DIRECTION * direction);
	void setMovingState(bool isM);
	void update();
	void handleInput();

private:
	const static int heroTextureNumber = 4;

	sf::Sprite _mySprite;
	sf::Texture _myTexture[4][heroTextureNumber];
	DIRECTION _direction;
	int _textureIndex;
	int _animationCount;
	bool _isMoving;
};