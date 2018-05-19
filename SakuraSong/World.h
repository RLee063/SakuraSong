#pragma once
#include <SFML\Graphics.hpp>
#include "MapManager.h"
#include "MenuManager.h"
#include "RoleManager.h"
#include "RenderManager.h"

class World
{
public:
	World();
	~World();
	void worldLoop();
	void handleInput(int code);
	void update();
private:
	sf::RenderWindow* _currentWindow;
	MenuManager * _currentMenuManager;
	MapManager * _currentMapManager;
	RoleManager * _currentRoleManager;
	RenderManager * _currentRenderManager;
};

