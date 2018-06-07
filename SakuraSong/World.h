#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include <list>
using namespace std;

class Scene;

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
	void pushScene(Scene * s);
	Scene* popScene();
	//void addObject(GameObject * obj);
	//void removeObject();
private:
	list<Scene*> _sceneList;
};