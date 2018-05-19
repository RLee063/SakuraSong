#pragma once
#include "Includes.h"
#include <list>

class Button {
public:
	sf::Sprite* getSprite();
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
class Menu
{
public:
	Menu();
	~Menu();
	virtual list<sf::Sprite*> getRenderList() = 0;
	virtual sf::Vector2i * getButtonIndex();
	virtual sf::Vector2i * getButtonNum();
	virtual sf::Sprite* getButtonBoxS();
	virtual Button*** getButtonArr();
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
	list<sf::Sprite*> getRenderList();
private:
};