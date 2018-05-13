#pragma once
#include "SFML\Graphics.hpp"
#include "Typedef.h"



class MapManager
{
public:
	MapManager();
	~MapManager();
	POSITION* getHeroPos();
	int** getMap();
	sf::Sprite* getMapSprite();
private:
	MAP _map[MAP_HEIGHT][MAP_WIDTH];
	POSITION _heroPos;
	sf::Sprite _map1Sprite;
	sf::Texture _map1Tex;
};