#include "Button.h"
#include "MapManager.h"
#include "Locator.h"
#include "RoleManager.h"
#include "BattleManager.h"
#include "testInclude.h"
#include <string>
#include "World.h"
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
	cout << "hello" << endl;
}

sf::Sprite * Button::getSprite()
{
	return &_mySprite;
}

void Button::update()
{
	Locator::getWindow()->draw(_mySprite);
}

AttackButton::AttackButton()
{
	_myTexture.loadFromFile("D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\mainButtons00.png");
	_mySprite.setTexture(_myTexture);
	_time = 0;
}

void AttackButton::selected()
{

	Locator::getWorld()->getScene()->addCommand(new HeroAttackCommand());
}

void AttackButton::update() {
	Button::update();
}