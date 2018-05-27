#pragma once
#include <SFML\Graphics.hpp>

class BattleManager;
class MapManager;
class MenuManager;
class RoleManager;
class RenderManager;
class Control;
class World;
class Creator;

class Locator{
public:
	~Locator();
	static void init(MapManager * map, MenuManager* menu, RoleManager* role, RenderManager* render, sf::RenderWindow * window, Control * cont, World* world, BattleManager* battleM, Creator * creator);
	static RenderManager * getRenderManager();
	static MenuManager * getMenuManager();
	static MapManager * getMapManager();
	static RoleManager * getRoleManager();
	static sf::RenderWindow* getWindow();
	static Control * getControl();
	static World * getWorld();
	static BattleManager * getBattleManager();
	static Creator * getCreator();

private:
	static sf::RenderWindow* _window;
	static MenuManager * _menuManager;
	static MapManager * _mapManager;
	static RoleManager * _currentRoleManager;
	static RenderManager * _currentRenderManager;
	static Control * _currentControl;
	static World * _currentWorld;
	static BattleManager * _battleM;
	static Creator * _creator;
};
