#include "World.h"
#include "testInclude.h"
World::World()
{
	Locator::init(new MapManager() , new MenuManager(), new RoleManager(), new RenderManager() , new sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "SakuraSong!"), new Control(),this, new BattleManager(), new Creator());
}

World::~World()
{
}

void World::worldLoop()
{
	sf::RenderWindow *window = Locator::getWindow();
	while (window->isOpen())
	{
		update();
		window->display();
		window->clear();
	}
}

void World::handleInput(int code)
{

}

void World::update()
{
	Locator::getControl()->update();
	_sceneList.back()->update();
	//Locator::getMapManager()->update();
	//Locator::getRoleManager()->update();
	//Locator::getMenuManager()->update();
	//Locator::getBattleManager()->update();
}

void World::start()
{
	_sceneList.push_back(Locator::getCreator()->createMap1Scene());
	worldLoop();
}

Scene * World::getScene()
{
	return _sceneList.back();
}

void World::pushScene(Scene * s)
{
	_sceneList.push_back(s);
}

Scene * World::popScene()
{
	Scene * s = _sceneList.back();
	_sceneList.pop_back();
	return s;
}

//void World::addObject(GameObject * obj)
//{
//	_objectList.push_back(obj);
//}
//
//void World::removeObject()
//{
//	_objectList.pop_back();
//} 