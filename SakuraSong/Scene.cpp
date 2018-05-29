#include "Scene.h"
#include "testInclude.h"
#include "Includes.h"
#include "Typedef.h"
Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::pushMenu(Menu * obj)
{
	_menuList.push_back(obj);
}

Menu * Scene::popMenu()
{
	Menu * obj = _menuList.back();
	_menuList.pop_back();
	return obj;
}

Menu* Scene::getCurrentMenu()
{
	return _menuList.back();
}

void Scene::addCommand(Command * cm)
{
	_commandList.push_back(cm);
}

NormalScene::NormalScene(MapBackGround * backG, char * mapInfoPath, sf::Vector2i* heroPos, Role * hero, Menu * mainMenu)
{
	ifstream fi;
	fi.open(mapInfoPath);
	fi >> _mapLength;
	fi >> _mapWidth;
	_mapInfo = (Terrain ***) new int**[_mapLength];
	for (int i = 0; i < _mapLength; i++) {
		_mapInfo[i] = (Terrain **) new int*[_mapWidth];
	}
	int terrainType;
	//must be x <=> y
	for (int i = 0; i < _mapLength; i++) {
		for (int j = 0; j < _mapWidth; j++) {
			fi >> terrainType;
			_mapInfo[j][i] = Locator::getCreator()->createTerrain((TERRAIN)terrainType, j, i);
		}
	}
	_mapG = backG;
	_heroPos = *heroPos;
	_hero = hero;
	_mainMenu = mainMenu;

	hero->getSprite()->setPosition(sf::Vector2f(float(UNIT_LENGTH*heroPos->x), (float)UNIT_LENGTH*heroPos->y));

	//_mapOfObject = new Role* *[_mapLength];
	//for (int i = 0; i < _mapLength; i++) {
	//	_mapOfObject[i] = new Role *[_mapWidth];
	//}
	//for (int i = 0; i < _mapLength; i++) {
	//	for (int j = 0; j < _mapWidth; j++) {
	//		_mapOfObject[i][j] = NULL;
	//	}
	//}
	_mapInfo[4][4]->hideEnemy(Locator::getCreator()->createEnemy());
}

void NormalScene::handleEvent()
{
	if (_menuList.size() == 0&& Locator::getControl()->ifPressedKey(sf::Keyboard::K)) {
		pushMenu(_mainMenu);
	}
	else if (_menuList.size() != 0 &&Locator::getControl()->ifPressedKey(sf::Keyboard::K)) {
		popMenu();
	}
	if (_mapInfo[_heroPos.x][_heroPos.y]->isHided()) {
		Scene * s = Locator::getCreator()->createBattle1Scene();
		((BattleScene*)s)->init(_hero, _mapInfo[_heroPos.x][_heroPos.y]->getEnemy());
		Locator::getWorld()->pushScene(s);
		_mapInfo[_heroPos.x][_heroPos.y]->killEnemy();
	}
}

void NormalScene::update()
{
	handleEvent();
	//_mapG->update();
	for (int i = 0; i < _mapLength; i++) {
		for (int j = 0; j < _mapWidth; j++) {
			_mapInfo[j][i]->update();
		}
	}
	_hero->update();
	if (_menuList.empty()) {
		return;
	}
	_menuList.back()->update();
}

void NormalScene::init()
{
	_hero->setState(Locator::getCreator()->createHeroStandState(_hero));
	_hero->getSprite()->setPosition(sf::Vector2f((float)(_heroPos.x*UNIT_LENGTH), float(_heroPos.y*UNIT_LENGTH)));
}

Terrain *** NormalScene::getMapInfo()
{
	return _mapInfo;
}

sf::Vector2i * NormalScene::getHeroPos()
{
	return &_heroPos;
}

Role * NormalScene::getHero()
{
	return _hero;
}

bool NormalScene::isMenuListEmpty()
{
	if (_menuList.empty()) {
		return 1;
	}
	else {
		return 0;
	}
}

BattleScene::BattleScene(BackGround * backG, Menu * mainMenu)
{
	_backG = backG;
	_mainMenu = mainMenu;
	_menuList.push_back(mainMenu);
}

void BattleScene::init(Role * hero, Role * enemy)
{
	_hero = hero;
	_enemy = enemy;
	_hero->setState(Locator::getCreator()->createRoleBattleState(_hero)); 
	_enemy->setState(Locator::getCreator()->createRoleBattleState(_enemy));
	_hero->getSprite()->setPosition(sf::Vector2f(((WINDOW_HEIGHT) / 5), (WINDOW_WIDTH) * 2 / 5));
	_enemy->getSprite()->setPosition(sf::Vector2f(((WINDOW_HEIGHT) * 3/ 5), (WINDOW_WIDTH) * 2 / 5));
}

void BattleScene::update()
{
	for (list<Command*>::iterator i = _commandList.begin(); i != _commandList.end();) {
		if ((*i)->excute()) {
			_commandList.erase(i++);
		}
		else {
			i++;
		}
	}
	handleEvent();
	if (!_ended) {
		_backG->update();
		_hero->update();
		_enemy->update();
		_menuList.back()->update();
	}
}

Role * BattleScene::getEnemy()
{
	return _enemy;
}

void BattleScene::handleEvent()
{
	if (_hero->isDied()) {
		Locator::getWorld()->popScene();
		Locator::getWorld()->getScene()->init();
		_ended = 1;
	}
	if (_enemy->isDied()) {
		Locator::getWorld()->popScene();
		Locator::getWorld()->getScene()->init();
		_ended = 1;
	}
}

Role * BattleScene::getHero()
{
	return _hero;
}
