#pragma once
#include "SFML\Graphics.hpp"
class Role;
class Terrain
{
public:
	Terrain(bool isMab, sf::Texture* t, int x, int y);
	~Terrain();
	bool isMoveable();
	bool isHided();
	bool hasNpc();
	void hideEnemy(Role * obj);
	void npcEnter(Role * obj);
	void npcLeft();
	void killEnemy();
	void update();
	void update2();
	void setBuild(sf::Sprite * s, bool moveable);
	void setMoveable(bool is);
	Role* getEnemy();
	Role* getNpc();
protected:
	bool _isMoveable;
	Role * _enemy;
	Role * _npc;
	sf::Sprite _mySprite;
	sf::Sprite * _build;
};