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
	fi >> _mapSize.x;
	fi >> _mapSize.y;
	_mapInfo = (Terrain ***) new int**[_mapSize.x];
	for (int i = 0; i < _mapSize.x; i++) {
		_mapInfo[i] = (Terrain **) new int*[_mapSize.y];
	}
	int terrainType;
	//must be x <=> y
	for (int i = 0; i < _mapSize.x; i++) {
		for (int j = 0; j < _mapSize.y; j++) {
			fi >> terrainType;
			_mapInfo[i][j] = Locator::getCreator()->createTerrain((TERRAIN)terrainType, i, j);
		}
	}
	_mapG = backG;
	_heroPos = *heroPos;
	_hero = hero;
	_mainMenu = mainMenu;
	_view = Locator::getWindow()->getView();
	_viewDirection = NODIRECTION;
	_isViewMoving = 0;
	hero->setPosition(sf::Vector2i(6, 6));
	_mapInfo[4][4]->hideEnemy(Locator::getCreator()->createEnemy());
	Role * npc1 = Locator::getCreator()->createEnemy();
	npc1->setPosition(sf::Vector2i(5, 7));
	_mapInfo[5][7]->npcEnter(npc1);
}

void NormalScene::handleEvent()
{
	if (_menuList.size() == 0&& Locator::getControl()->ifPressedKey(sf::Keyboard::K)) {
		pushMenu(_mainMenu);
		Locator::getControl()->clearKey(sf::Keyboard::K);
	}
	if (_mapInfo[_heroPos.x][_heroPos.y]->isHided()) {
		Scene * s = Locator::getCreator()->createBattle1Scene();
		((BattleScene*)s)->init(_hero, _mapInfo[_heroPos.x][_heroPos.y]->getEnemy());
		Locator::getWorld()->pushScene(s);
		_mapInfo[_heroPos.x][_heroPos.y]->killEnemy();
	}
	Control * control = Locator::getControl();
	if (!_isViewMoving) {
		if (control->ifPressedKey(sf::Keyboard::W)) {
			_viewDirection = UP;
		}
		if (control->ifPressedKey(sf::Keyboard::S)) {
			_viewDirection = DOWN;
		}
		if (control->ifPressedKey(sf::Keyboard::A)) {
			_viewDirection = LEFT;
		}
		if (control->ifPressedKey(sf::Keyboard::D)) {
			_viewDirection = RIGHT;
		}
		if (_viewDirection != NODIRECTION && _isViewMoveable()) {
			_commandList.push_back(new ViewMoveCommand(this));
			_isViewMoving = 1;
		}
	}
}

void NormalScene::update()
{
	handleEvent();
	//_mapG->update();
	for (list<Command*>::iterator i = _commandList.begin(); i != _commandList.end();) {
		if ((*i)->excute()) {
			_commandList.erase(i++);
		}
		else {
			i++;
		}
	}
	Locator::getWindow()->setView(_view);
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			_mapInfo[i][j]->update();
		}
	}
	_hero->update();
	if (!_menuList.empty()) {
		_menuList.back()->update();
	}
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

sf::Vector2i * NormalScene::getMapSize()
{
	return &_mapSize;
}

sf::Vector2i * NormalScene::getLeftUpPoint()
{
	return &_leftUpPoint;
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

sf::View * NormalScene::getView()
{
	return &_view;
}

bool NormalScene::_isViewMoveable()
{
	return 1;
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
