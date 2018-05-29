#include "Command.h"
#include "Includes.h"
Command::Command()
{
}


Command::~Command()
{
}

HeroAttackCommand::HeroAttackCommand()
{
	_hero = ((BattleScene*)Locator::getWorld()->getScene())->getHero();
	_enemy = ((BattleScene*)Locator::getWorld()->getScene())->getEnemy();
	_scene = ((BattleScene*)Locator::getWorld()->getScene());
}

bool HeroAttackCommand::excute()
{
	if (_time++ < 40 * ANIMATION_DELAY) {
		if (_time == 1* ANIMATION_DELAY) {
			_hero->attack(_enemy);
			_scene->pushMenu(new DialogBox());
		}
		if (_time == 30 * ANIMATION_DELAY) {
			_enemy->attack(_hero);
			_scene->popMenu();
			_scene->pushMenu(new DialogBox());
		}
		return 0;
	}
	else {
		_scene->popMenu();
		return 1;
	}
}
