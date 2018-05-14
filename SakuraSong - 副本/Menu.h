#pragma once
#include "Includes.h"
#include <list>
using namespace std;
class Menu
{
public:
	Menu();
	~Menu();
	sf::Sprite* getFramWorkS();
	list<sf::Sprite*> getButtonsSList();
private:
	sf::Sprite _framework;
	sf::Texture _frameworkT;
	list<sf::Sprite*> _buttonsList;
	list<sf::Texture*> _buttonsTList;
	sf::Sprite _selectBox;
};