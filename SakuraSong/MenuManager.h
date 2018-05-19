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
	void update();
	void add(Menu * menu);
	void leftMenu();
private:
	Menu * _mainMenu;
	Menu * _currentMenu;
	list<Menu*> _menuList;
};