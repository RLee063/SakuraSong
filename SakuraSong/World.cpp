#include "World.h"
#include "Includes.h"
World::World()
{
	Locator::init(new sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT_PIX, WINDOW_WIDTH_PIX), "SakuraSong!"), new Control(),this, new Creator());
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