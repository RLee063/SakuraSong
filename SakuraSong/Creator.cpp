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
	NormalScene * scene = new NormalScene(new MapBackGround(MAP1_TEXTURE_PATH), MAP1_CONFIG_PATH, &sf::Vector2i(6, 6), Locator::getRoleManager()->getHero(), new MainMenu());
	_map1Scene = scene;
	return scene;
}

Scene * Creator::createBattle1Scene()
{
	if (_battle1Scene != NULL) {
		return _battle1Scene;
	}
	BattleScene * scene = new BattleScene(new BackGround(BATTLE1_TEXTURE_PATH), new BattleMainMenu());
	_battle1Scene = scene;
	return scene;
}

Role * Creator::createHero()
{
	Role * hero = new Role();
	string path1 = HERO_TEXTURE_PATH;
	string type = ".png";
	//set texture
	sf::Texture *** mvT = hero->getMoveTexture();
	*mvT = new sf::Texture *[4];
	for (int i = 0; i < 4; i++) {
		(*mvT)[i] = new sf::Texture[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			(*mvT)[i][j].loadFromFile(path1 + "move" + to_string(i) + to_string(j) + type);
		}
	}
	sf::Texture ** sT = hero->getStandTexture();
	*sT = new sf::Texture[4];
	for (int i = 0; i < 4; i++) {
		(*sT)[i].loadFromFile(path1 + "stand" + to_string(i) + type);
	}
	sf::Texture ** bT = hero->getBattleTexture();
	*bT = new sf::Texture;
	(*(*bT)).loadFromFile(path1 + "battle" + type);
	//set initial state
	RoleState * state = createHeroStandState(hero);
	hero->setState(state);
	DIRECTION dir = LEFT;
	hero->setDirection(&dir);
	return hero;
}

Role * Creator::createEnemy()
{
	Role * enemy = new Role();
	string path1 = HUOLONG_TEXTURE_PATH;
	string type = ".png";
	sf::Texture ** bT = enemy->getBattleTexture();
	*bT = new sf::Texture;
	(*(*bT)).loadFromFile(path1 + "battle" + type);
	RoleState * state = createRoleBattleState(enemy);
	enemy->setState(state);
	return enemy;
}

Terrain * Creator::createTerrain(TERRAIN terType, int x, int y)
{
	string path1 = TERRAIN_TEXTURE_PATH;
	string suffix = ".png";
	string type;
	Terrain * ter;
	bool isMable;
	switch (terType)
	{
	case DIRT:
		type = "dirt";
		isMable = 1;
		break;
	case GRASS:
		type = "grass";
		isMable = 0;
		break;
	default:
		break;
	}
	sf::Texture* t = new sf::Texture;
	t->loadFromFile(path1 + type + suffix);
	ter = new Terrain(isMable, t, x*UNIT_LENGTH, y*UNIT_LENGTH);
	return ter;
}

RoleState * Creator::createHeroStandState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleStandGraphicImplement(obj), new RoleIdlePhysicsIplement(obj), new RoleStandHandleImplement(obj));
	return state;
}

RoleState * Creator::createRoleMoveState(Role* obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleMoveGraphicImplement(obj), new RoleMovePhysicsImplement(obj), new RoleIdleHandleImplement(obj));
	return state;
}

RoleState * Creator::createRoleBattleState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleBattleGraphicImplement(obj) ,new RoleIdlePhysicsIplement(obj), new RoleIdleHandleImplement(obj));
	return state;
}

RoleState * Creator::createRoleAttackState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleBattleGraphicImplement(obj), new RoleAttackPhysicsIplement(obj), new RoleIdleHandleImplement(obj));
	return state;
}

RoleState * Creator::createRoleInjuredState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleBattleGraphicImplement(obj), new RoleInjurePhysicsImplement(obj), new RoleIdleHandleImplement(obj));
	return state;
}
