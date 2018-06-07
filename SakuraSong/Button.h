#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;
class Button : public GameObject {
public:
	Button(float x, float y);
	sf::Sprite* getSprite();
	virtual void update();
	virtual void selected() = 0;
	virtual void updatePos(sf::Vector2f mPos);
protected:
	sf::Sprite _mySprite;
	sf::Texture _myTexture;
	sf::Vector2f _relaPos;
	sf::Text _text;
	sf::Font _font;
};

class MainMenuButton :public Button {
public:
	MainMenuButton(float x, float y);
	void selected();
private:
};

class AttackButton :public Button {
public:
	AttackButton(float x, float y);
	void selected();
	void update();
private:
	int _time;
};

class DialogButton :public Button {
public:
	DialogButton(float x, float y);
	void selected();
	void update();
};

class BattleButton :public Button {
public:
	BattleButton(float x, float y);
	void selected();
	void update();
};

class SaveButton : public Button {
public:
	SaveButton(float x, float y);
	void selected();
	void update();
};

class ContinueButton :public Button {
public:
	ContinueButton(float x, float y);
	void selected();
	void update();
};

class RestartButton :public Button {
public:
	RestartButton(float x, float y);
	void selected();
	void update();
};

class QuitButton :public Button {
public:
	QuitButton(float x, float y);
	void selected();
	void update();
};