#pragma once
#include <SFML\Graphics.hpp>

class Control;
class World;
class Creator;

class Locator{
public:
	~Locator();
	static void init(sf::RenderWindow * window, Control * cont, World* world, Creator * creator);
	static sf::RenderWindow* getWindow();
	static Control * getControl();
	static World * getWorld();
	static Creator * getCreator();
private:
	static sf::RenderWindow* _window;
	static Control * _currentControl;
	static World * _currentWorld;
	static Creator * _creator;
};
