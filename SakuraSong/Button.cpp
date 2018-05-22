#include "Button.h"
#include "Locator.h"
#include <string>
using namespace std;

MainMenuButton::MainMenuButton(int i_x, int i_y)
{
	string Path1 = "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainButtons";
	string Path2 = to_string(i_x);
	string Path3 = to_string(i_y);
	string Path4 = ".png";
	_myTexture.loadFromFile(Path1 + Path2 + Path3 + Path4);
	_mySprite.setTexture(_myTexture);
}

void MainMenuButton::selected()
{
	cout << "fuck u" << endl;
}

sf::Sprite * Button::getSprite()
{
	return &_mySprite;
}

void Button::update()
{
	Locator::getWindow()->draw(_mySprite);
}
