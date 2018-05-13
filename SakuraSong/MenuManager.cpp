#include "MenuManager.h"



MenuManager::MenuManager()
{
	Menu * mainMenuP = new Menu();
	_mainMenu = mainMenuP;
}


MenuManager::~MenuManager()
{
}

Menu * MenuManager::getMainMenu()
{
	return _mainMenu;
}

Menu * MenuManager::getCurrentMenu()
{
	return _currentMenu;
}
