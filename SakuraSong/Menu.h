#pragma once
#include "Typedef.h"
#include <list>
#include "GameObject.h"
#include "Locator.h"
#include "Button.h"
using namespace std;

class Role;

class Menu : public GameObject
{
public:
	virtual void update();
	virtual void setPosition(sf::Vector2f pos);
protected:
	sf::Sprite _framework;
	sf::Texture _frameworkT;
};

class DialogBox : public Menu {
public:
	DialogBox(int sleep, bool passAble, char * dialog, Role * who);
	virtual void setPosition(sf::Vector2f pos);
	void handleInput();
	void update();
private:
	int _time;
	int _sleep;
	bool _passAble;
	Role * _who;
	sf::Text _dialog;
	sf::Font _font;
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
	virtual void setPosition(sf::Vector2f hp);
	virtual void moveButton(DIRECTION dir);
	virtual bool isButtomMoveable(DIRECTION dir);
	virtual void handleInput();
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
};

class BattleMainMenu : public buttonMenu {
public:
	BattleMainMenu();
	void update();
private:
};

class GuideMenu :public buttonMenu {
public:
	GuideMenu();
	void update();
private:

};