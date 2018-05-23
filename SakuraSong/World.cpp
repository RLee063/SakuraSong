#include "World.h"
#include "Locator.h"
#include <SFML\Graphics.hpp>
#include "Control.h"
#include "BattleManager.h"
World::World()
{
	Locator::init(new MapManager() , new MenuManager(), new RoleManager(), new RenderManager() , new sf::RenderWindow(sf::VideoMode(MAP_HEIGHT_PIX, MAP_WIDTH_PIX), "SFML works!"), new Control(),this, new BattleManager());
}

World::~World()
{
}

void World::worldLoop()
{
	sf::RenderWindow *window = Locator::getWindow();
	while (window->isOpen())
	{
		//sf::Event event;
		//while (window->pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window->close();

		//	if (event.type == sf::Event::KeyPressed)
		//	{
		//		handleInput(event.key.code);
		//	}
		//}
		update();
		window->display();
		window->clear();
	}
}

void World::handleInput(int code)
{
	DIRECTION dir = NODIRECTION;
	switch (code)
	{
	case sf::Keyboard::W:
		dir = UP;
		break;
	case sf::Keyboard::S:
		dir = DOWN;
		break;
	case sf::Keyboard::A:
		dir = LEFT;
		break;
	case sf::Keyboard::D:
		dir = RIGHT;
		break;
	}

	if (Locator::getMenuManager()->getCurrentMenu() == NULL) {
		switch (code)
		{
		case sf::Keyboard::K:
			//_expManager->getExeManager()->add(new OpenMainMenu(_expManager));
			break;
		default:

			break;
		}
		if (dir != NODIRECTION) {
			Locator::getRoleManager()->getHero()->startMove(&dir);
		}
		return ;
	}
	else {
		//switch (code)
		//{
	/*	case sf::Keyboard::K:
			_expManager->getExeManager()->add(new LeftMainMenu(_expManager));
			return 0;
			break;
		default:

			break;
		}
		if (dir != NODIRECTION) {
			if (_expManager->isButtonBoxMoveable(dir)) {
				_expManager->getExeManager()->add(new ButtonBoxMove(_expManager, dir));
			}
		}*/
		return ;
	}
}

void World::update()
{
	Locator::getControl()->update();
	Locator::getMapManager()->update();
	Locator::getRoleManager()->update();
	Locator::getMenuManager()->update();
	Locator::getBattleManager()->update();
}

void World::addObject(GameObject * obj)
{
	_objectList.push_back(obj);
}

void World::removeObject()
{
	_objectList.pop_back();
} 