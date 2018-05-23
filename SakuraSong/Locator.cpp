#include "Locator.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "RoleManager.h"
#include "RenderManager.h"
#include "Control.h"
#include "World.h"
#include "BattleManager.h"

sf::RenderWindow* Locator::_currentWindow;
MapManager*  Locator::_currentMapManager;
MenuManager* Locator::_currentMenuManager;
RoleManager* Locator::_currentRoleManager;
RenderManager* Locator::_currentRenderManager;
Control * Locator::_currentControl;
World * Locator::_currentWorld;
BattleManager * Locator::_battleM;

void Locator::init(MapManager * map, MenuManager* menu, RoleManager* role, RenderManager* render, sf::RenderWindow * window, Control * cont, World * world, BattleManager * battleM)
{
	_battleM = battleM;
	_currentMapManager = map;
	_currentMenuManager = menu;
	_currentRoleManager = role;
	_currentRenderManager = render;
	_currentWindow = window;
	_currentControl = cont;
	_currentWorld = world;
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

Control * Locator::getControl()
{
	return _currentControl;
}

World * Locator::getWorld()
{
	return _currentWorld;
}

BattleManager * Locator::getBattleManager()
{
	return _battleM;
}

