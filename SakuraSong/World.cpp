#include "World.h"
#include "Locator.h"
#include <SFML\Graphics.hpp>

World::World()
{
	_currentMapManager = new MapManager();
	_currentMenuManager = new MenuManager();
	_currentRoleManager = new RoleManager();
	_currentRenderManager = new RenderManager();
	_currentWindow = new sf::RenderWindow(sf::VideoMode(MAP_HEIGHT_PIX, MAP_WIDTH_PIX), "SFML works!");
	Locator::init(_currentMapManager, _currentMenuManager, _currentRoleManager, _currentRenderManager, _currentWindow);
}

World::~World()
{
}

void World::worldLoop()
{
	sf::RenderWindow *window = Locator::getWindow();
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			if (event.type == sf::Event::KeyPressed)
			{
				handleInput(event.key.code);
			}
		}
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
		switch (code)
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
	_currentMapManager->update();
	_currentMenuManager->update();
	_currentRoleManager->update();
}
