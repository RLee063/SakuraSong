#pragma once
#define HERO_TEXTURE_NUMBER 1
#include <SFML\Graphics.hpp>
class Hero
{
public:
	Hero();
	~Hero();
	sf::Sprite* getSprite();
private:
	sf::Sprite _mySprite;
	sf::Texture _myTexture[HERO_TEXTURE_NUMBER];
};