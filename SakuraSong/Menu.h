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
	sf::Vector2i * getButtonIndex();
	sf::Vector2i * getButtonNum();
	sf::Sprite* getButtonBoxS();
	Button*** getButtonArr();
	virtual void update();
	virtual void moveButton(DIRECTION dir);
	virtual bool isButtomMoveable(DIRECTION dir);
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
	void update();
	void handleInput();
};