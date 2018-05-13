#include "Menu.h"

Menu::Menu()
{
	_frameworkT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainMenuFramwork.png");
	_framework.setTexture(_frameworkT);
	_framework.setPosition(sf::Vector2f(0, 500));
	for (int i = 0; i < 2; i++) {
		sf::Sprite* sp = new sf::Sprite();
		sf::Texture* tp = new sf::Texture();
		tp->loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\buttons.png");
		sp->setTexture(*tp);
		_buttonsList.push_back(sp);
		_buttonsTList.push_back(tp);
		sp->setPosition(sf::Vector2f((float)(i+1) * 200, 600));
	}
}

Menu::~Menu(){
}

sf::Sprite * Menu::getFramWorkS()
{
	return &_framework;
}

list<sf::Sprite*> Menu::getButtonsSList()
{
	return _buttonsList;
}

