#pragma once
#include "Includes.h"
#include "list"

class Menu;
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
	void update();
private:
	Menu * _mainMenu;
	Menu * _currentMenu;
	list<Menu*> _menuList;
};