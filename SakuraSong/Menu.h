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
private:
};
#define MAINMENU_BUTTON_NUM_X 2
#define MAINMENU_BUTTON_NUM_Y 2

class MainMenu :public Menu{
public:
	MainMenu();
	list<sf::Sprite*> getRenderList();
private:
	sf::Sprite _framework;
	sf::Texture _frameworkT;
	Button * _buttonsArr[MAINMENU_BUTTON_NUM_X][MAINMENU_BUTTON_NUM_Y];
};