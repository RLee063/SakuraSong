#pragma once
#include "Includes.h"
#include <list>
#include "GameObject.h"
#include "Locator.h"
#include "Button.h"

using namespace std;
class Menu : public GameObject
{
public:
	virtual void update();
protected:
	sf::Sprite _framework;
	sf::Texture _frameworkT;
};

class DialogBox : public Menu {
public:
	DialogBox();
	void update();
private:
	int _time;
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
	sf::Sprite _selectedBox;
	sf::Texture _selectedBoxT;
};


class MainMenu :public buttonMenu{
public:
	MainMenu();
	void update();
private:
	void handleInput();
};

class BattleMainMenu : public buttonMenu {
public:
	BattleMainMenu();
	void update();
private:
	void handleInput();
};