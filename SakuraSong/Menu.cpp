#include "Menu.h"
#include <SFML\Graphics.hpp>
#include "Includes.h"

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
	sf::RenderWindow * window = Locator::getWindow();
	for (int i = 0; i < _buttonNum.x; i++) {
		for (int j = 0; j < _buttonNum.y; j++) {
			(_buttonsArr[i][j]->update());
		}
	}
	window->draw(_selectedBox);
}
void buttonMenu::setPosition(sf::Vector2f hp)
{
	Menu::setPosition(hp);
	hp.x -= WINDOW_WIDTH / 2 * UNIT_LENGTH - 10;
	hp.y += WINDOW_HEIGHT / 4 * UNIT_LENGTH - 60;
	for (int i = 0; i < _buttonNum.x; i++) {
		for (int j = 0; j < _buttonNum.y; j++) {
			_buttonsArr[i][j]->updatePos(hp);
		}
	}
	_selectedBox.setPosition(_buttonsArr[_buttonIndex.x][_buttonIndex.y]->getSprite()->getPosition());
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

void buttonMenu::handleInput()
{
	if ((Locator::getWorld()->getScene())->getCurrentMenu() == this) {
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
		if (Locator::getControl()->ifPressedKey(sf::Keyboard::K)) {
			Locator::getWorld()->getScene()->popMenu();
			Locator::getControl()->clearKey(sf::Keyboard::K);
		}
		if (dir != NODIRECTION) {
			moveButton(dir);
		}
	}
}

MainMenu::MainMenu()
{
	_buttonNum.x = 2;
	_buttonNum.y = 2;
	_buttonsArr = new Button **[_buttonNum.x];
	for (int i = 0; i < _buttonNum.x; i++) {
		_buttonsArr[i] = new Button *[_buttonNum.y];
	}

	_frameworkT.loadFromFile(MENU1_FRAME_TEXTURE_PATH);
	_framework.setTexture(_frameworkT);

	_buttonsArr[0][0] = new DialogButton(50, 25);
	_buttonsArr[0][1] = new QuitButton(530, 25);
	_buttonsArr[1][0] = new SaveButton(50, 150);
	_buttonsArr[1][1] = new BattleButton(530, 150);

	//for (int i = 0; i < _buttonNum.x; i++) {
	//	for (int j = 0; j < _buttonNum.y; j++) {
	//		_buttonsArr[i][j] = new DialogButton();
	//		_buttonsArr[i][j]->getSprite()->setPosition((float)
	//		MAIN_MENU_POSITION_X + 50 + (j*((MAIN_MENU_WEIGHTH - 150)/_buttonNum.x)),
	//			(float)
	//			MAIN_MENU_POSITION_Y + 20 + (i*((MAIN_MENU_HEIGHT - 60) / _buttonNum.y))
	//		);	
	//	}
	//}
	_selectedBoxT.loadFromFile(BUTTON1_SELECTED_TEXTURE_PATH);
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


void Menu::update()
{
	Locator::getWindow()->draw(_framework);
}

void Menu::setPosition(sf::Vector2f pos)
{
	pos.x -= WINDOW_WIDTH / 2 * UNIT_LENGTH - 10;
	pos.y += WINDOW_HEIGHT / 4 * UNIT_LENGTH - 60;
	_framework.setPosition(pos);
}

BattleMainMenu::BattleMainMenu()
{
	_buttonNum.x = 2;
	_buttonNum.y = 2;
	_buttonsArr = new Button **[_buttonNum.x];
	for (int i = 0; i < _buttonNum.x; i++) {
		_buttonsArr[i] = new Button *[_buttonNum.y];
	}

	_frameworkT.loadFromFile(MENU1_FRAME_TEXTURE_PATH);
	_framework.setTexture(_frameworkT);
	_framework.setPosition(sf::Vector2f(MAIN_MENU_POSITION_X, MAIN_MENU_POSITION_Y));
	//for (int i = 0; i < _buttonNum.x; i++) {
	//	for (int j = 0; j < _buttonNum.y; j++) {
	//		_buttonsArr[i][j] = new MainMenuButton(i, j);
	//		_buttonsArr[i][j]->getSprite()->setPosition((float)
	//			MAIN_MENU_POSITION_X + 50 + (j*((MAIN_MENU_WEIGHTH - 150) / _buttonNum.x)),
	//			(float)
	//			MAIN_MENU_POSITION_Y + 20 + (i*((MAIN_MENU_HEIGHT - 60) / _buttonNum.y))
	//		);
	//	}
	//}
	_buttonsArr[0][0] = new AttackButton(50, 25);
	_buttonsArr[0][1] = new AttackButton(530, 25);
	_buttonsArr[1][0] = new AttackButton(50, 150);
	_buttonsArr[1][1] = new AttackButton(530, 150);


	_selectedBoxT.loadFromFile(BUTTON1_SELECTED_TEXTURE_PATH);
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


DialogBox::DialogBox(int sleep, bool passAble, char * dialog, Role* who)
{
	_frameworkT.loadFromFile(MENU2_FRAME_TEXTURE_PATH);
	_framework.setTexture(_frameworkT);
	_framework.setPosition(sf::Vector2f(MAIN_MENU_POSITION_X, MAIN_MENU_POSITION_Y));
	_sleep = sleep;
	_time = 0;
	_passAble = passAble;
	_font.loadFromFile(FONT1_PATH);
	_dialog.setFont(_font);
	_dialog.setString(dialog);
	_dialog.setPosition(sf::Vector2f(MAIN_MENU_POSITION_X + 50, MAIN_MENU_POSITION_Y + 50));
	_who = who;
}

void DialogBox::setPosition(sf::Vector2f pos)
{
	Menu::setPosition(pos);
	pos.x -= WINDOW_WIDTH / 2 * UNIT_LENGTH - 10 - 50;
	pos.y += WINDOW_HEIGHT / 4 * UNIT_LENGTH - 60 + 50;
	_dialog.setPosition(pos);
}

void DialogBox::handleInput()
{
	if (_passAble && Locator::getControl()->ifPressedKey(sf::Keyboard::J)) {
		Locator::getControl()->clearKey(sf::Keyboard::J);
	}
	else if (_time++ > _sleep) {
	}
	else {
		return;
	}
	Locator::getWorld()->getScene()->popMenu();
	_time = 0;
	if (_who != NULL) {
		_who->setTalkState(0);
	}
}

void DialogBox::update()
{
	handleInput();
	Menu::update();
	Locator::getWindow()->draw(_dialog);
}

GuideMenu::GuideMenu()
{
	_buttonNum.x = 1;
	_buttonNum.y = 2;
	_buttonsArr = new Button **[_buttonNum.x];
	for (int i = 0; i < _buttonNum.x; i++) {
		_buttonsArr[i] = new Button *[_buttonNum.y];
	}
	_frameworkT.loadFromFile(MENU1_FRAME_TEXTURE_PATH);
	_framework.setTexture(_frameworkT);
	_buttonsArr[0][0] = new ContinueButton(50, 25);
	_buttonsArr[0][1] = new RestartButton(530, 25);

	_selectedBoxT.loadFromFile(BUTTON1_SELECTED_TEXTURE_PATH);
	_selectedBox.setTexture(_selectedBoxT);
	_selectedBox.setPosition(_buttonsArr[0][0]->getSprite()->getPosition());
	_buttonIndex.x = 0;
	_buttonIndex.y = 0;
}

void GuideMenu::update()
{
	handleInput();
	//graphic
	buttonMenu::update();
}
