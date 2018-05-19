#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu(){

}
sf::Vector2i * Menu::getButtonIndex()
{
	return &_buttonIndex;
}
sf::Vector2i * Menu::getButtonNum()
{
	return &_buttonNum;
}
sf::Sprite * Menu::getButtonBoxS()
{
	return &_selectedBox;
}
Button *** Menu::getButtonArr()
{
	return _buttonsArr;
}
#define MAIN_MENU_POSITION_X 0
#define MAIN_MENU_POSITION_Y 500
#define MAIN_MENU_HEIGHT 300
#define MAIN_MENU_WEIGHTH 800
MainMenu::MainMenu()
{
	_buttonNum.x = 2;
	_buttonNum.y = 2;

	_buttonsArr = new Button **[_buttonNum.x];
	for (int i = 0; i < _buttonNum.x; i++) {
		_buttonsArr[i] = new Button *[_buttonNum.y];
	}

	_frameworkT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainMenuFramwork.png");
	_framework.setTexture(_frameworkT);
	_framework.setPosition(sf::Vector2f(MAIN_MENU_POSITION_X, MAIN_MENU_POSITION_Y));
	for (int i = 0; i < _buttonNum.x; i++) {
		for (int j = 0; j < _buttonNum.y; j++) {
			_buttonsArr[i][j] = new MainMenuButton(i, j);
			_buttonsArr[i][j]->getSprite()->setPosition((float)
			MAIN_MENU_POSITION_X + 50 + (j*((MAIN_MENU_WEIGHTH - 150)/_buttonNum.x)),
				(float)
				MAIN_MENU_POSITION_Y + 20 + (i*((MAIN_MENU_HEIGHT - 60) / _buttonNum.y))
			);
		}
	}
	_selectedBoxT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainButtonSelected.png");
	_selectedBox.setTexture(_selectedBoxT);
	_selectedBox.setPosition(_buttonsArr[0][0]->getSprite()->getPosition());
	_buttonIndex.x = 0;
	_buttonIndex.y = 0;
}

list<sf::Sprite*> MainMenu::getRenderList()
{
	list<sf::Sprite*> sList;
	sList.push_back(&_framework);
	for (int i = 0; i < _buttonNum.x; i++) {
		for (int j = 0; j < _buttonNum.y; j++) {
			sList.push_back(_buttonsArr[i][j]->getSprite());
		}
	}
	sList.push_back(&_selectedBox);
	return sList;
}

MainMenuButton::MainMenuButton(int i_x, int i_y)
{
	string Path1 = "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainButtons";
	string Path2 = to_string(i_x);
	string Path3 = to_string(i_y);
	string Path4 = ".png";
	_myTexture.loadFromFile(Path1+Path2+Path3+Path4);
	_mySprite.setTexture(_myTexture);
}

sf::Sprite * Button::getSprite()
{
	return &_mySprite;
}
