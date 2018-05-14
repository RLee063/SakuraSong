#include "MenuManager.h"



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

void MenuManager::switchToMainMenu()
{
	_currentMenu = _mainMenu;
	_menuList.push_back(_mainMenu);
}

void MenuManager::leftMainMenu()
{
	_currentMenu = NULL;
	_menuList.pop_back();
}

list<sf::Sprite*> MenuManager::getRenderList()
{
	list<sf::Sprite*> sList;
	for (auto i : _menuList) {
		for (auto j : i->getRenderList()) {
			sList.push_back(j);
		}
	}
	return sList;
}
