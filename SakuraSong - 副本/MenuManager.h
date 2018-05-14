#pragma once
#include "Includes.h"
#include "Menu.h"
class MenuManager
{
public:
	MenuManager();
	~MenuManager();
	Menu * getMainMenu();
	Menu * getCurrentMenu();
private:
	Menu * _mainMenu;
	Menu * _currentMenu;
};