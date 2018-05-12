#pragma once
#include "Executor.h"
#include "Hero.h"
#include <SFML\Graphics.hpp>

class HeroMoveUp : public Executor {
public:
	HeroMoveUp(Hero * hero) {
		_hero = hero;
	}
	bool execute() {
		sf::Sprite * mS = _hero->getSprite();
		mS->move(sf::Vector2f(0, 5));
		return 0;
	}
private:
	Hero * _hero;
};