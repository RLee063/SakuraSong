#include "Scene.h"
#include "Includes.h"
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

NormalScene::NormalScene(char * mapInfoPath, sf::Vector2i* heroPos, Role * hero, Menu * mainMenu)
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

	int buildType;
	bool moveable;
	for (int i = 0; i < _mapSize.x; i++) {
		for (int j = 0; j < _mapSize.y; j++) {
			fi >> buildType;
			if (buildType == NOBUILD) {
				continue;
			}
			else if (buildType < 100) {
				moveable = 0;
			}
			else {
				moveable = 1;
			}
			_mapInfo[i][j]->setBuild(Locator::getCreator()->createBuild((BUILD)buildType), moveable);
		}
	}

	_heroPos = *heroPos;
	_hero = hero;
	_mainMenu = mainMenu;
	_originView = Locator::getWindow()->getView();
	_view = _originView;
	hero->setPosition(_heroPos);
	_menuList.push_back(new GuideMenu());
}

void NormalScene::handleEvent()
{
	if (_menuList.size() == 0 && Locator::getControl()->ifPressedKey(sf::Keyboard::K)) {
		pushMenu(_mainMenu);
		Locator::getControl()->clearKey(sf::Keyboard::K);
	}
	if (_mapInfo[_heroPos.x][_heroPos.y]->isHided()) {
		Scene * s = Locator::getCreator()->createBattle1Scene();
		((BattleScene*)s)->init(_hero, _mapInfo[_heroPos.x][_heroPos.y]->getEnemy());
		Locator::getWorld()->pushScene(s);
		_mapInfo[_heroPos.x][_heroPos.y]->killEnemy();
		Locator::getWindow()->setView(_originView);
	}
	Control * control = Locator::getControl();
}

void NormalScene::update()
{
	_updateView();
	//_mapG->update();
	for (list<Command*>::iterator i = _commandList.begin(); i != _commandList.end();) {
		if ((*i)->excute()) {
			_commandList.erase(i++);
		}
		else {
			i++;
		}
	}
	for (int i = _heroPos.x - (WINDOW_HEIGHT / 2) - 1; i < _heroPos.x + (WINDOW_HEIGHT / 2) + 1; i++) {
		for (int j = _heroPos.y - (WINDOW_HEIGHT / 2) - 1; j < _heroPos.y + (WINDOW_HEIGHT / 2) + 1; j++) {
			_mapInfo[i][j]->update();
		}
	}

	for (int i = _heroPos.x - (WINDOW_HEIGHT / 2) - 1; i < _heroPos.x + (WINDOW_HEIGHT / 2) + 1; i++) {
		for (int j = _heroPos.y - (WINDOW_HEIGHT / 2) - 1; j < _heroPos.y + (WINDOW_HEIGHT / 2) + 1; j++) {
			_mapInfo[i][j]->update2();
		}
	}
	//_hero->update();
	if (!_menuList.empty()) {
		_menuList.back()->setPosition(_hero->getSprite()->getPosition());
		_menuList.back()->update();
	}
	handleEvent();
}

void NormalScene::init()
{
	_hero->setState(Locator::getCreator()->createHeroStandState(_hero));
	_hero->getSprite()->setPosition(sf::Vector2f((float)(_heroPos.y*UNIT_LENGTH), float(_heroPos.x*UNIT_LENGTH)));
	/////
	Locator::getWindow()->draw(*_hero->getSprite());
}

Terrain *** NormalScene::getMapInfo()
{
	return _mapInfo;
}

Terrain * NormalScene::getTerrain(int x, int y)
{
	return _mapInfo[x][y];
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

sf::View * NormalScene::getOriginView()
{
	return &_originView;
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

bool NormalScene::isBlockMoveable(int x, int y)
{
	if (x < 0 || y < 0 || x >= _mapSize.x || y >= _mapSize.y) {
		return 0;
	}
	else {
		return _mapInfo[x][y]->isMoveable();
	}
}

sf::View * NormalScene::getView()
{
	return &_view;
}

void NormalScene::npcEnter(int x, int y, Role * role)
{
	_mapInfo[x][y]->npcEnter(role);
}

void NormalScene::npcLeft(int x, int y)
{
	_mapInfo[x][y]->npcLeft();
}

void NormalScene::setHeroPos(sf::Vector2i p)
{
	_heroPos = p;
	_hero->setPosition(p);
}

void NormalScene::setEnemyPos(sf::Vector2i p)
{
	_enemyPos = p;
}

sf::Vector2i * NormalScene::getEnemyPos()
{
	return &_enemyPos;
}

void NormalScene::_updateView()
{
	sf::Vector2f heroPosPix = _hero->getSprite()->getPosition();
	_view.setCenter(heroPosPix);
	Locator::getWindow()->setView(_view);
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
	hero->setInBattleTexture(1);
	enemy->setInBattleTexture(0);
	_hero->setState(Locator::getCreator()->createRoleBattleState(_hero));
	_enemy->setState(Locator::getCreator()->createRoleBattleState(_enemy));
	_hero->getSprite()->setPosition(sf::Vector2f(((WINDOW_HEIGHT_PIX) / 5), (WINDOW_WIDTH_PIX) * 2 / 5));
	_enemy->getSprite()->setPosition(sf::Vector2f(((WINDOW_HEIGHT_PIX) * 3 / 5), (WINDOW_WIDTH_PIX) * 2 / 5));
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
	}
	else if (_enemy->isDied()) {
		Locator::getWorld()->popScene();
		NormalScene * ns = ((NormalScene *)Locator::getWorld()->getScene());
		sf::Vector2i ep = *ns->getEnemyPos();
		Terrain*** map = ns->getMapInfo();
		map[ep.x][ep.y]->npcLeft();
		map[ep.x][ep.y]->killEnemy();
	}
	else {
		return;
	}

	Locator::getWorld()->getScene()->init();
	_ended = 1;

	ROLETYPE rt = _enemy->getType();
	sf::Vector2i ep = *((NormalScene*)Locator::getWorld()->getScene())->getEnemyPos();
	switch (rt)
	{
	case MOVENPC:
		_enemy->setState(Locator::getCreator()->createNpcStandState(_enemy));
		swap(ep.x, ep.y);
		_enemy->getSprite()->setPosition((sf::Vector2f)(ep * UNIT_LENGTH));
		break;
	case ENEMY:
		break;
	case STOPNPC:
		_enemy->setState(Locator::getCreator()->createRoleStandState(_enemy));
		swap(ep.x, ep.y);
		_enemy->getSprite()->setPosition((sf::Vector2f)(ep * UNIT_LENGTH));
		break;
	default:
		break;
	}
}

Role * BattleScene::getHero()
{
	return _hero;
}
