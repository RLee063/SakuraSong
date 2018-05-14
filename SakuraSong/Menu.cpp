#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu(){

}
#define MAIN_MENU_POSITION_X 0
#define MAIN_MENU_POSITION_Y 500
#define MAIN_MENU_HEIGHT 300
#define MAIN_MENU_WEIGHTH 800
MainMenu::MainMenu()
{
	_frameworkT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainMenuFramwork.png");
	_framework.setTexture(_frameworkT);
	_framework.setPosition(sf::Vector2f(MAIN_MENU_POSITION_X, MAIN_MENU_POSITION_Y));
	for (int i = 0; i < MAINMENU_BUTTON_NUM_X; i++) {
		for (int j = 0; j < MAINMENU_BUTTON_NUM_Y; j++) {
			_buttonsArr[i][j] = new MainMenuButton(i, j);
			_buttonsArr[i][j]->getSprite()->setPosition((float)
			MAIN_MENU_POSITION_X + 50 + (j*((MAIN_MENU_WEIGHTH - 150)/MAINMENU_BUTTON_NUM_X)),
				(float)
				MAIN_MENU_POSITION_Y + 20 + (i*((MAIN_MENU_HEIGHT - 60) / MAINMENU_BUTTON_NUM_Y))
			);
		}
	}
}

list<sf::Sprite*> MainMenu::getRenderList()
{
	list<sf::Sprite*> sList;
	sList.push_back(&_framework);
	for (int i = 0; i < MAINMENU_BUTTON_NUM_X; i++) {
		for (int j = 0; j < MAINMENU_BUTTON_NUM_Y; j++) {
			sList.push_back(_buttonsArr[i][j]->getSprite());
		}
	}
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
