#pragma once
#include "SFML\Graphics.hpp"
#include "Includes.h"
#include <list>
using namespace std;


class MapManager
{
public:
	MapManager();
	~MapManager();
	sf::Vector2i* getHeroPos();
	int** getMap();
	sf::Sprite* getMapSprite();
	void update();
private:
	
	MAP _map[MAP_HEIGHT][MAP_WIDTH];
	sf::Vector2i _heroPos;
	sf::Sprite _map1Sprite;
	sf::Texture _map1Tex;
};