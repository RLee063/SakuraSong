#pragma once
#include "Includes.h"
#include <list>
#include "GameObject.h"
#include "Locator.h"

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

using namespace std;
class Menu : public GameObject
{
public:
	Menu();
	~Menu();
	virtual sf::Vector2i * getButtonIndex();
	virtual sf::Vector2i * getButtonNum();
	virtual sf::Sprite* getButtonBoxS();
	virtual Button*** getButtonArr();
	virtual void update();
protected:
	sf::Vector2i _buttonNum;
	sf::Vector2i _buttonIndex;
	Button *** _buttonsArr;
	sf::Sprite _framework;
	sf::Texture _frameworkT;
	sf::Sprite _selectedBox;
	sf::Texture _selectedBoxT;
};


class MainMenu :public Menu{
public:
	MainMenu();
private:
};