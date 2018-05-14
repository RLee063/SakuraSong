#pragma once
#include "Includes.h"
#include "Menu.h"
#include "list"
using namespace std;
class MenuManager
{
public:
	MenuManager();
	~MenuManager();
	Menu * getMainMenu();
	Menu * getCurrentMenu();
	void switchToMainMenu();
	void leftMainMenu();
	list<sf::Sprite*> getRenderList();
private:
	Menu * _mainMenu;
	Menu * _currentMenu;
	list<Menu*> _menuList;
};