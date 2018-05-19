#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
class Button : public GameObject {
public:
	sf::Sprite* getSprite();
	virtual void update();
protected:
	sf::Sprite _mySprite;
	sf::Texture _myTexture;
};

class MainMenuButton :public Button {
public:
	MainMenuButton(int i_x, int i_y);
private:
};