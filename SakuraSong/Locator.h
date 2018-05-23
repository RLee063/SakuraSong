#pragma once
#include <SFML\Graphics.hpp>

class BattleManager;
class MapManager;
class MenuManager;
class RoleManager;
class RenderManager;
class Control;
class World;

class Locator{
public:
	~Locator();
	static void init(MapManager * map, MenuManager* menu, RoleManager* role, RenderManager* render, sf::RenderWindow * window, Control * cont, World* world, BattleManager* battleM);
	static RenderManager * getRenderManager();
	static MenuManager * getMenuManager();
	static MapManager * getMapManager();
	static RoleManager * getRoleManager();
	static sf::RenderWindow* getWindow();
	static Control * getControl();
	static World * getWorld();
	static BattleManager * getBattleManager();

private:
	static sf::RenderWindow* _currentWindow;
	static MenuManager * _currentMenuManager;
	static MapManager * _currentMapManager;
	static RoleManager * _currentRoleManager;
	static RenderManager * _currentRenderManager;
	static Control * _currentControl;
	static World * _currentWorld;
	static BattleManager * _battleM;
};
