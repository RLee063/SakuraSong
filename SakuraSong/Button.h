#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;
class Button : public GameObject {
public:
	sf::Sprite* getSprite();
	virtual void update();
	virtual void selected() = 0;
protected:
	sf::Sprite _mySprite;
	sf::Texture _myTexture;
};

class MainMenuButton :public Button {
public:
	MainMenuButton(int i_x, int i_y);
	void selected();
private:
};

class AttackButton :public Button {
public:
	AttackButton();
	void selected();
	void update();
private:
	int _time;
};