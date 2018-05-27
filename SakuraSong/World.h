#pragma once
#include <SFML\Graphics.hpp>
#include "MapManager.h"
#include "MenuManager.h"
#include "RoleManager.h"
#include "RenderManager.h"
#include "GameObject.h"
#include "Scene.h"
#include <list>
using namespace std;

class World
{
public:
	World();
	~World();
	void worldLoop();
	void handleInput(int code);
	void update();
	void start();
	Scene * getScene();
	//void addObject(GameObject * obj);
	//void removeObject();
private:
	//list<GameObject *> _objectList;
	Scene * _scene;
};