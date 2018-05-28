#include "Creator.h"
#include "testInclude.h"
#include "Typedef.h"

Creator::Creator()
{

}


Creator::~Creator()
{

}

Scene * Creator::createMap1Scene()
{
	if (_map1Scene != NULL) {
		return _map1Scene;
	}
	NormalScene * scene = new NormalScene();
	scene->init(MAP1_TEXTURE_PATH, MAP1_CONFIG_PATH, &sf::Vector2i(6,6), Locator::getRoleManager()->getHero());
	_map1Scene = scene;
	return scene;
}

Role * Creator::createHero()
{
	Role * hero = new Role();
	string path1 = HERO_TEXTURE_PATH;
	string type = ".png";
	//set texture
	sf::Texture ** mvT = hero->getMoveTexture();
	mvT = new sf::Texture *[4];
	for (int i = 0; i < 4; i++) {
		mvT[i] = new sf::Texture[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mvT[i][j].loadFromFile(path1 + "move" + to_string(i) + to_string(j) + type);
		}
	}
	sf::Texture * sT = hero->getStandTexture();
	sT = new sf::Texture[4];
	for (int i = 0; i < 4; i++) {
		sT[i].loadFromFile(path1 + "stand" + to_string(i) + type);
	}
	sf::Texture * bT = hero->getBattleTexture();
	bT = new sf::Texture;
	(*bT).loadFromFile(path1 + "battle" + type);
	//set initial state
	RoleState * state = createRoleStandState(hero);
}

RoleState * Creator::createRoleStandState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleStandGraphicImplement(obj), new RoleStandPhysicsImplement(obj));
	return state;
}
