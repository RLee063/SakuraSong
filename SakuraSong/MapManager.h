#pragma once
#include "SFML\Graphics.hpp"
#include "Includes.h"
#include <list>
#include "GameObject.h"
using namespace std;

class MapManager
{
public:
	MapManager();
	~MapManager();
	sf::Vector2i* getHeroPos();
	int** getMapInfo();
	sf::Sprite* getMapSprite();
	void update();
	//---------temp--------
	void swatchBack();
private:
	MAPINFO _map[MAP_HEIGHT][MAP_WIDTH];
	GameObject * _mapO[MAP_HEIGHT][MAP_WIDTH];
	sf::Vector2i _heroPos;
	sf::Sprite _backGroundS;
	sf::Texture _battle1T;
	sf::Texture _map1Tex;
};