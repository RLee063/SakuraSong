#include "MenuManager.h"
#include "Menu.h"
MenuManager::MenuManager()
{
	Menu * mainMenuP = new MainMenu();
	_mainMenu = mainMenuP;
	_currentMenu = NULL;
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

void MenuManager::leftMenu()
{
	_currentMenu->invisible();
	_menuList.pop_back();
	if (_menuList.empty()) {
		_currentMenu = NULL;
	}
	else {
		_currentMenu = _menuList.back();
		_currentMenu->visible();
	}
}

void MenuManager::update()
{
	if (_currentMenu == NULL) {
		_mainMenu->update();
	}
	else {
		_currentMenu->update();
	}
}

void MenuManager::add(Menu * menu)
{
	_menuList.push_back(menu);
	_currentMenu = menu;
	menu->visible();
}
