#pragma once
#define HERO_TEXTURE_NUMBER 4
#include "Typedef.h"
#include <SFML\Graphics.hpp>
class Hero
{
public:
	Hero();
	~Hero();
	sf::Sprite* getSprite();
	void setDirection(DIRECTION* dir);
	void setNextTexture();
	DIRECTION* getDirection();
	bool isMoving();
	void setMovingState(bool isM);
private:
	sf::Sprite _mySprite;
	sf::Texture _myTexture[HERO_TEXTURE_NUMBER];
	DIRECTION _direction;
	int _textureIndex;
	bool _isMoving;
};