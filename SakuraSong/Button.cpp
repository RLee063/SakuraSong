#include "Includes.h"
#include <string>
#include <fstream>
using namespace std;

MainMenuButton::MainMenuButton(float x, float y)
	:Button(x, y)
{
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void MainMenuButton::selected()
{
	cout << "hello" << endl;
}

Button::Button(float x, float y)
{
	_relaPos.x = x;
	_relaPos.y = y;
	_mySprite.setPosition(sf::Vector2f(x + MAIN_MENU_POSITION_X, y + MAIN_MENU_POSITION_Y));
	_font.loadFromFile(FONT1_PATH);
	_text.setFont(_font);
	_text.setPosition(sf::Vector2f(x + MAIN_MENU_POSITION_X+20, y + MAIN_MENU_POSITION_Y+20));
}

sf::Sprite * Button::getSprite()
{
	return &_mySprite;
}

void Button::update()
{
	Locator::getWindow()->draw(_mySprite);
	Locator::getWindow()->draw(_text);
}

void Button::updatePos(sf::Vector2f mPos)
{
	_mySprite.setPosition(_relaPos + mPos);
	_text.setPosition(_relaPos + mPos + sf::Vector2f(20,20));
}

AttackButton::AttackButton(float x, float y)
	:Button(x, y)
{
	_text.setString("Attack");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
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

DialogButton::DialogButton(float x, float y)
	:Button(x, y)
{
	_text.setString("Talk");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void DialogButton::selected()
{
	sf::Vector2i* heroPos = ((NormalScene *)Locator::getWorld()->getScene())->getHeroPos();
	Terrain *** map = ((NormalScene *)Locator::getWorld()->getScene())->getMapInfo();
	DIRECTION * dir = ((NormalScene *)Locator::getWorld()->getScene())->getHero()->getDirection();
	Role * npc = NULL;

	switch (*dir)
	{
	case UP:
		npc = map[heroPos->x-1][heroPos->y]->getNpc();
		break;
	case DOWN:
		npc = map[heroPos->x+1][heroPos->y]->getNpc();
		break;
	case LEFT:
		npc = map[heroPos->x][heroPos->y-1]->getNpc();
		break;
	case RIGHT:
		npc = map[heroPos->x][heroPos->y+1]->getNpc();
		break;
	default:
		break;
	}
	if (npc != NULL) {
		npc->setTalkState(1);
		list<Menu *> dL = npc->getDialogList();
		for (auto i : dL) {
			((NormalScene *)Locator::getWorld()->getScene())->pushMenu(i);
		}
	}
	else {
		((NormalScene *)Locator::getWorld()->getScene())->pushMenu(new DialogBox(500, 1, "No NPC!\n FUCK U!", NULL));
	}
}

void DialogButton::update()
{
	Button::update();
}

BattleButton::BattleButton(float x, float y)
	:Button(x, y)
{
	_text.setString("Battle");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void BattleButton::selected()
{
	sf::Vector2i* heroPos = ((NormalScene *)Locator::getWorld()->getScene())->getHeroPos();
	Terrain *** map = ((NormalScene *)Locator::getWorld()->getScene())->getMapInfo();
	DIRECTION * dir = ((NormalScene *)Locator::getWorld()->getScene())->getHero()->getDirection();
	Role * npc = NULL;

	switch (*dir)
	{
	case UP:
		npc = map[heroPos->x - 1][heroPos->y]->getNpc();
		break;
	case DOWN:
		npc = map[heroPos->x + 1][heroPos->y]->getNpc();
		break;
	case LEFT:
		npc = map[heroPos->x][heroPos->y - 1]->getNpc();
		break;
	case RIGHT:
		npc = map[heroPos->x][heroPos->y + 1]->getNpc();
		break;
	default:
		break;
	}
	NormalScene* ns = (NormalScene*)Locator::getWorld()->getScene();
	if (npc != NULL) {

		sf::Vector2f pos = ns->getHero()->getSprite()->getPosition();

		Scene * s = Locator::getCreator()->createBattle1Scene();
		((BattleScene*)s)->init(ns->getHero(), npc);
		Locator::getWorld()->pushScene(s);
		ns->popMenu();
		ns->setEnemyPos(*npc->getPosition());
		Locator::getWindow()->setView(*ns->getOriginView());
	}
	else {
		ns->pushMenu(new DialogBox(500, 1, "No NPC!!!!", NULL));
	}
}

void BattleButton::update()
{
	Button::update();
}

SaveButton::SaveButton(float x, float y)
	:Button(x, y)
{
	_text.setString("Save");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void SaveButton::selected()
{
	sf::Vector2i* pos = ((NormalScene*)Locator::getWorld()->getScene())->getHeroPos();
	Locator::getWorld()->getScene()->pushMenu(new DialogBox(500, 1, "Sava successful!", NULL));
	fstream sf;
	sf.open(SAVE_CONFIG_PATH);
	sf << pos->x;
	sf << " ";
	sf << pos->y;
	sf.close();
}

void SaveButton::update()
{
	Button::update();
}

ContinueButton::ContinueButton(float x, float y)
	:Button(x, y)
{
	_text.setString("Continue");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void ContinueButton::selected()
{
	sf::Vector2i pos;
	fstream sf;
	sf.open(SAVE_CONFIG_PATH);
	if (sf.eof()) {
		Locator::getWorld()->getScene()->popMenu();
		Locator::getWorld()->getScene()->pushMenu(new DialogBox(500, 1, "NO CUNDANG", NULL));
	}
	sf >> pos.x;
	sf >> pos.y;

	((NormalScene*)Locator::getWorld()->getScene())->setHeroPos(pos);
	Locator::getWorld()->getScene()->popMenu();
}

void ContinueButton::update()
{
	Button::update();
}

RestartButton::RestartButton(float x, float y)
	:Button(x, y)
{
	_text.setString("New");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void RestartButton::selected()
{
	Locator::getWorld()->getScene()->popMenu();
}

void RestartButton::update()
{
	Button::update();
}

QuitButton::QuitButton(float x, float y)
	:Button(x, y)
{
	_text.setString("Quit");
	_myTexture.loadFromFile(BUTTON1_TEXTURE_PATH);
	_mySprite.setTexture(_myTexture);
}

void QuitButton::selected()
{
	exit(0);
}

void QuitButton::update()
{
	Button::update();
}
