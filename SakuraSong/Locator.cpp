#include "Locator.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "RoleManager.h"
#include "RenderManager.h"
#include "Control.h"
#include "World.h"
#include "BattleManager.h"
#include "Creator.h"

sf::RenderWindow* Locator::_window;
MapManager*  Locator::_mapManager;
MenuManager* Locator::_menuManager;
RoleManager* Locator::_currentRoleManager;
RenderManager* Locator::_currentRenderManager;
Control * Locator::_currentControl;
World * Locator::_currentWorld;
BattleManager * Locator::_battleM;
Creator * Locator::_creator;

void Locator::init(MapManager * map, MenuManager* menu, RoleManager* role, RenderManager* render, sf::RenderWindow * window, Control * cont, World * world, BattleManager * battleM, Creator * creator)
{
	_battleM = battleM;
	_mapManager = map;
	_menuManager = menu;
	_currentRoleManager = role;
	_currentRenderManager = render;
	_window = window;
	_currentControl = cont;
	_currentWorld = world;
	_creator = creator;
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
	return _menuManager;
}



MapManager * Locator::getMapManager()
{
	return _mapManager;
}

RoleManager * Locator::getRoleManager()
{
	return _currentRoleManager;
}

sf::RenderWindow * Locator::getWindow()
{
	return _window;
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

Creator * Locator::getCreator()
{
	return _creator;
}