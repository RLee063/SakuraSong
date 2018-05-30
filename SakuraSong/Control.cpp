#include "Control.h"
#include <iostream>
using namespace std;

Control::Control()
{
	_isEnable = 1;
}


Control::~Control()
{
}

void Control::update()
{
	if (!_isEnable) {
		return;
	}
	clear();
	sf::Event event;
	sf::RenderWindow *window = Locator::getWindow();
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			char * des = (char*)&_keyPressed;
			*(des + event.key.code) = 1;
		}
	}
}

void Control::clear()
{
	memset(&_keyPressed, 0, sizeof(KEY_EVENT));
	memset(&_keyRleased, 0, sizeof(KEY_EVENT));
}

bool Control::ifPressedKey(int code)
{
	return *((bool*)&_keyPressed + code);
}

void Control::clearKey(int code)
{
	char * des = (char*)&_keyPressed;
	*(des + code) = 0;
}

void Control::enable()
{
	_isEnable = 1;
}

void Control::disable()
{
	_isEnable = 0;
}
