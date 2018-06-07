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
			_scene->pushMenu(new DialogBox(999999, 0, "Attacking!", NULL));
		}
		if (_time == 30 * ANIMATION_DELAY) {
			_enemy->attack(_hero);
			_scene->popMenu();
			_scene->pushMenu(new DialogBox(999999, 0, "OH~ So sick!", NULL));
		}
		return 0;
	}
	else {
		_scene->popMenu();
		return 1;
	}
}

//ViewMoveCommand::ViewMoveCommand(NormalScene * s)
//{
//	_scene = s;
//	_count = 0;
//	_window = Locator::getWindow();
//}
//
//bool ViewMoveCommand::excute()
//{
//	if (_time++ % ANIMATION_DELAY != 0) {
//		return 0;
//	}
//	switch (_scene->_viewDirection)
//	{
//	case UP:
//		_scene->_view.move(sf::Vector2f(0, -WALK_LENGTH / 4));
//		break;
//	case DOWN:
//		_scene->_view.move(sf::Vector2f(0, WALK_LENGTH / 4));
//		break;
//	case LEFT:
//		_scene->_view.move(sf::Vector2f(-WALK_LENGTH / 4, 0));
//		break;
//	case RIGHT:
//		_scene->_view.move(sf::Vector2f(WALK_LENGTH / 4, 0));
//		break;
//	default:
//		break;
//	}
//	_window->setView(_scene->_view);
//	_count++;
//	if (_count > ROLE_ANIMATION_COUNT - 1) {
//		sf::Vector2i * lup = ((NormalScene*)Locator::getWorld()->getScene())->getLeftUpPoint();
//		switch (_scene->_viewDirection)
//		{
//		case UP:
//			lup->x -= 1;
//			break;
//		case DOWN:
//			lup->x += 1;
//			break;
//		case LEFT:
//			lup->y -= 1;
//			break;
//		case RIGHT:
//			lup->y += 1;
//			break;
//		default:
//			break;
//		}
//		_scene->_isViewMoving = 0;
//		_scene->_viewDirection = NODIRECTION;
//		return 1;
//	}
//	return 0;
//}
