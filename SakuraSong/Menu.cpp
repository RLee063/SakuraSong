#include "Menu.h"
#include <SFML\Graphics.hpp>
#include "MenuManager.h"
#include "Control.h"

buttonMenu::buttonMenu()
{
}

buttonMenu::~buttonMenu(){

}

sf::Vector2i * buttonMenu::getButtonIndex()
{
	return &_buttonIndex;
}
sf::Vector2i * buttonMenu::getButtonNum()
{
	return &_buttonNum;
}
sf::Sprite * buttonMenu::getButtonBoxS()
{
	return &_selectedBox;
}
Button *** buttonMenu::getButtonArr()
{
	return _buttonsArr;
}
void buttonMenu::update()
{
	//graphic
	Menu::update();
	if (!_isVisible) {
		return;
	}
	sf::RenderWindow * window = Locator::getWindow();
	for (int i = 0; i < _buttonNum.x; i++) {
		for (int j = 0; j < _buttonNum.y; j++) {
			window->draw(*_buttonsArr[i][j]->getSprite());
		}
	}
	window->draw(_selectedBox);
}
void buttonMenu::moveButton(DIRECTION dir)
{
	if (isButtomMoveable(dir)) {
		switch (dir)
		{
		case UP:
			_buttonIndex.x -= 1;
			break;
		case DOWN:
			_buttonIndex.x += 1;
			break;
		case LEFT:
			_buttonIndex.y -= 1;
			break;
		case RIGHT:
			_buttonIndex.y += 1;
			break;
		default:
			break;
		}
		_selectedBox.setPosition(_buttonsArr[_buttonIndex.x][_buttonIndex.y]->getSprite()->getPosition());
	}
}

bool buttonMenu::isButtomMoveable(DIRECTION dir)
{
	switch (dir)
	{
	case UP:
		if (_buttonIndex.x - 1 < 0) return 0;
		break;
	case DOWN:
		if (_buttonIndex.x + 1 >= _buttonNum.x) return 0;
		break;
	case LEFT:
		if (_buttonIndex.y - 1 < 0) return 0;
		break;
	case RIGHT:
		if (_buttonIndex.y + 1 >= _buttonNum.y) return 0;
		break;
	default:
		break;
	}
	return 1;
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

void MainMenu::update()
{
	handleInput();
	//graphic
	buttonMenu::update();
}

void MainMenu::handleInput()
{
	if (Locator::getMenuManager()->getCurrentMenu() != NULL) {
		if (Locator::getMenuManager()->getCurrentMenu() == this) {
			DIRECTION dir = NODIRECTION;
			if (Locator::getControl()->ifPressedKey(sf::Keyboard::W)) {
				dir = UP;
			}
			if (Locator::getControl()->ifPressedKey(sf::Keyboard::S)) {
				dir = DOWN;
			}
			if (Locator::getControl()->ifPressedKey(sf::Keyboard::A)) {
				dir = LEFT;
			}
			if (Locator::getControl()->ifPressedKey(sf::Keyboard::D)) {
				dir = RIGHT;
			}
			if (Locator::getControl()->ifPressedKey(sf::Keyboard::J)) {
				_buttonsArr[_buttonIndex.x][_buttonIndex.y]->selected();
			}
			if (dir != NODIRECTION) {
				moveButton(dir);
			}
			if (Locator::getControl()->ifPressedKey(sf::Keyboard::K)) {
				Locator::getMenuManager()->leftMenu();
			}
		}
	}
	else {
		if(Locator::getControl()->ifPressedKey(sf::Keyboard::K)){
			Locator::getMenuManager()->add(this);
		}
	}
}

void Menu::update()
{
	if (_isVisible) {
		Locator::getWindow()->draw(_framework);
	}
}

BattleMainMenu::BattleMainMenu()
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
				MAIN_MENU_POSITION_X + 50 + (j*((MAIN_MENU_WEIGHTH - 150) / _buttonNum.x)),
				(float)
				MAIN_MENU_POSITION_Y + 20 + (i*((MAIN_MENU_HEIGHT - 60) / _buttonNum.y))
			);
		}
	}
	_buttonsArr[0][0] = new AttackButton();
	_buttonsArr[0][0]->getSprite()->setPosition(MAIN_MENU_POSITION_X + 50, MAIN_MENU_POSITION_Y + 20);
	_selectedBoxT.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainButtonSelected.png");
	_selectedBox.setTexture(_selectedBoxT);
	_selectedBox.setPosition(_buttonsArr[0][0]->getSprite()->getPosition());
	_buttonIndex.x = 0;
	_buttonIndex.y = 0;
}

void BattleMainMenu::update()
{
	handleInput();
	//graphic
	buttonMenu::update();
}

void BattleMainMenu::handleInput()
{
	if (Locator::getMenuManager()->getCurrentMenu() == this) {
		DIRECTION dir = NODIRECTION;
		if (Locator::getControl()->ifPressedKey(sf::Keyboard::W)) {
			dir = UP;
		}
		if (Locator::getControl()->ifPressedKey(sf::Keyboard::S)) {
			dir = DOWN;
		}
		if (Locator::getControl()->ifPressedKey(sf::Keyboard::A)) {
			dir = LEFT;
		}
		if (Locator::getControl()->ifPressedKey(sf::Keyboard::D)) {
			dir = RIGHT;
		}
		if (Locator::getControl()->ifPressedKey(sf::Keyboard::J)) {
			_buttonsArr[_buttonIndex.x][_buttonIndex.y]->selected();
		}
		if (dir != NODIRECTION) {
			moveButton(dir);
		}
	}
}
