#include "Locator.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "RoleManager.h"
#include "RenderManager.h"

sf::RenderWindow* Locator::_currentWindow;
MapManager*  Locator::_currentMapManager;
MenuManager* Locator::_currentMenuManager;
RoleManager* Locator::_currentRoleManager;
RenderManager* Locator::_currentRenderManager;


void Locator::init(MapManager * map, MenuManager* menu, RoleManager* role, RenderManager* render, sf::RenderWindow * window)
{
	_currentMapManager = map;
	_currentMenuManager = menu;
	_currentRoleManager = role;
	_currentRenderManager = render;
	_currentWindow = window;
}

Locator::~Locator()
{

}

RenderManager * Locator::getRenderManager()
{
	return _currentRenderManager;
}

MenuManager * Locator::getMenuManager()
{
	return _currentMenuManager;
}



MapManager * Locator::getMapManager()
{
	return _currentMapManager;
}

RoleManager * Locator::getRoleManager()
{
	return _currentRoleManager;
}

sf::RenderWindow * Locator::getWindow()
{
	return _currentWindow;
}

