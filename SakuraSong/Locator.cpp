#include "Includes.h"

sf::RenderWindow* Locator::_window;

Control * Locator::_currentControl;
World * Locator::_currentWorld;

Creator * Locator::_creator;

void Locator::init(sf::RenderWindow * window, Control * cont, World * world, Creator * creator)
{
	_window = window;
	_currentControl = cont;
	_currentWorld = world;
	_creator = creator;
}

Locator::~Locator()
{

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


Creator * Locator::getCreator()
{
	return _creator;
}