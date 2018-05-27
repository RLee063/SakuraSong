#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class BackGround :public GameObject
{
public:
	BackGround();
	~BackGround();
	void update();
protected:
	sf::Texture _backT;
	sf::Sprite _backS;
};

class MapBackGround :public BackGround {
public:
	MapBackGround(char * tPath);
	void update();
};