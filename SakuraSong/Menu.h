#pragma once
#include "Includes.h"
#include <list>
#include "GameObject.h"
#include "Locator.h"
#include "Button.h"

using namespace std;
class Menu : public GameObject
{
};

class buttonMenu : public Menu {
public:
	buttonMenu();
	~buttonMenu();
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


class MainMenu :public buttonMenu{
public:
	MainMenu();
private:
	void update();
	void handleInput();
};