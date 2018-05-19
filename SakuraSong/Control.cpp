#include "Control.h"
#include <iostream>
using namespace std;

Control::Control()
{
}


Control::~Control()
{
}

void Control::update()
{
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
	return *((char*)&_keyPressed + code);
}
