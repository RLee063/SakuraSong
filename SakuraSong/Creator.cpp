#include "Creator.h"
#include "Includes.h"
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
	Role * hero = createHero();

	NormalScene * scene = new NormalScene(MAP1_CONFIG_PATH, &sf::Vector2i(HERO_STARTPOSITION_X, HERO_STARTPOSITION_Y),hero , new MainMenu());

	Terrain*** mapInfo =  scene->getMapInfo();
	sf::Vector2i heroPos = *hero->getPosition();

	(mapInfo)[heroPos.x][heroPos.y]->npcEnter(hero);

	(mapInfo)[14][14]->hideEnemy(Locator::getCreator()->createRole(FIREDRAGON));


	Role * npc1 = Locator::getCreator()->createRole(FIREDRAGON);
	npc1->setPosition(sf::Vector2i(17, 17));
	mapInfo[17][17]->npcEnter(npc1);

	for (int i = 10; i < 20; i++) {
		Role * npc2 = Locator::getCreator()->createRole(TURTOISE);
		npc2->setPosition(sf::Vector2i(10, i));
		mapInfo[10][i]->npcEnter(npc2);
	}

	for (int i = 10; i < 20; i++) {
		Role * npc3 = Locator::getCreator()->createRole(TUDOU);
		npc3->setPosition(sf::Vector2i(20, i));
		mapInfo[20][i]->npcEnter(npc3);
	}
	
	for (int i = 10; i < 20; i++) {
		Role * npc4 = Locator::getCreator()->createRole(FIREDRAGON2);
		npc4->setPosition(sf::Vector2i(i, 30));
		mapInfo[i][30]->npcEnter(npc4);
	}

	//for (int i = 12; i < 18; i++) {
	//	mapInfo[12][i]->setBuild(createBuild(TREE1));
	//	mapInfo[12][i]->setMoveable(0);
	//}

	//for (int i = 12; i < 18; i++) {
	//	mapInfo[13][i]->setBuild(createBuild(DEADTREE1));
	//	mapInfo[13][i]->setMoveable(0);
	//}

	_map1Scene = scene;
	return scene;
}

Scene * Creator::createBattle1Scene()
{
	BattleScene * scene = new BattleScene(new BackGround(BATTLE1_TEXTURE_PATH), new BattleMainMenu());
	return scene;
}

Role * Creator::createHero()
{
	Role * hero = new Role(5000, 50, HERO);
	string path1 = PIKA_TEXTURE_PATH;
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

//Role * Creator::createEnemy()
//{
//	Role * enemy = new Role(200, 10, OTHER);
//	string path1 = FIREDRAGON_TEXTURE_PATH;
//	string type = ".png";
//	//texture
//	sf::Texture *** mvT = enemy->getMoveTexture();
//	*mvT = new sf::Texture *[4];
//	for (int i = 0; i < 4; i++) {
//		(*mvT)[i] = new sf::Texture[4];
//	}
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			(*mvT)[i][j].loadFromFile(path1 + "move" + to_string(i) + to_string(j) + type);
//		}
//	}
//	sf::Texture ** sT = enemy->getStandTexture();
//	*sT = new sf::Texture[4];
//	for (int i = 0; i < 4; i++) {
//		(*sT)[i].loadFromFile(path1 + "stand" + to_string(i) + type);
//	}
//	sf::Texture ** bT = enemy->getBattleTexture();
//	*bT = new sf::Texture;
//	//state
//	(*(*bT)).loadFromFile(path1 + "battle" + type);
//	RoleState * state = createRoleStandState(enemy);
//	enemy->setState(state);
//	DIRECTION dir = DOWN;
//	enemy->setDirection(&dir);
//	//dialogBox
//	enemy->pushDialog(new DialogBox(5000, 1, "HELLO MY FRIEND!", enemy));
//	return enemy;
//}

Role * Creator::createRole(ROLE rType)
{
	Role * role = NULL;
	string path1;
	string type = ".png";
	RoleState * state = NULL;
	switch (rType)
	{
	case PIKA:
		role = new Role(5000, 100, MOVENPC);
		path1 = PIKA_TEXTURE_PATH;
		state = createNpcStandState(role);
		role->pushDialog(new DialogBox(5000, 1, "LOOK YOUR MOTHER!", role));
		break;
	case FIREDRAGON:
		role = new Role(300, 100, STOPNPC);
		path1 = FIREDRAGON_TEXTURE_PATH;
		state = createRoleStandState(role);
		role->pushDialog(new DialogBox(5000, 1, "HELLO MY FRIEND!", role));
		break;
	case TURTOISE:
		role = new Role(300, 100, MOVENPC);
		path1 = TURTOISE_TEXTURE_PATH;
		state = createNpcStandState(role);
		role->pushDialog(new DialogBox(5000, 1, "WHY YOU COME HERE?", role));
		break;
	case TUDOU:
		role = new Role(300, 100, MOVENPC);
		path1 = TUDOU_TEXTURE_PATH;
		state = createNpcStandState(role);
		role->pushDialog(new DialogBox(5000, 1, "IM TUDOU!", role));
		break;
	case FIREDRAGON2:
		role = new Role(300, 100, MOVENPC);
		path1 = FIREDRAGON_TEXTURE_PATH;
		state = createNpcStandState(role);
		role->pushDialog(new DialogBox(5000, 1, "FIRE U!!!!", role));
		break;
	default:
		break;
	}
	//state
	role->setState(state);
	//direction
	DIRECTION dir = DOWN;
	role->setDirection(&dir);

	//texture
	//Move
	sf::Texture *** mvT = role->getMoveTexture();
	*mvT = new sf::Texture *[4];
	for (int i = 0; i < 4; i++) {
		(*mvT)[i] = new sf::Texture[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			(*mvT)[i][j].loadFromFile(path1 + "move" + to_string(i) + to_string(j) + type);
		}
	}
	//Stand
	sf::Texture ** sT = role->getStandTexture();
	*sT = new sf::Texture[4];
	for (int i = 0; i < 4; i++) {
		(*sT)[i].loadFromFile(path1 + "stand" + to_string(i) + type);
	}
	//Battle
	sf::Texture ** bT = role->getBattleTexture();
	*bT = new sf::Texture;
	(*(*bT)).loadFromFile(path1 + "battle" + type);
	//BeBattle
	sf::Texture ** bbT = role->getBeBattledTexture();
	*bbT = new sf::Texture;
	(*(*bbT)).loadFromFile(path1 + "bebattled" + type);
	return role;
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
		isMable = 1;
		break;
	case WATER:
		type = "water";
		isMable = 0;
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
	state->init(new RoleStandGraphicImplement(obj), new RoleIdlePhysicsIplement(obj), new HeroStandHandleImplement(obj));
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

RoleState * Creator::createRoleStandState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleStandGraphicImplement(obj), new RoleIdlePhysicsIplement(obj), new RoleIdleHandleImplement(obj));
	return state;
}

RoleState * Creator::createNpcStandState(Role * obj)
{
	RoleState * state = new RoleState(obj);
	state->init(new RoleStandGraphicImplement(obj), new RoleIdlePhysicsIplement(obj), new NpcStandHandleimplement(obj));
	return state;
}

sf::Sprite * Creator::createBuild(BUILD buildType)
{
	string type;
	switch (buildType)
	{
	case B_TREE1:
		type = "tree1";
		break;
	case B_DEADTREE1:
		type = "deadtree1";
		break;
	case NOBUILD:
		return NULL;
		break;
	case B_SEA:
		return NULL;
		break;
	case B_GROUND1:
		type = "ground1";
		break;
	case B_GROUND2:
		type = "ground2";
		break;
	case B_TREE2:
		type = "tree2";
		break;
	case B_HOUSE1:
		type = "house1";
		break;
	default:
		return NULL;
		break;
	}
	string path1 = BUILD_TEXTURE_PATH;
	string suffix = ".png";
	sf::Sprite * s = new sf::Sprite;
	sf::Texture* t = new sf::Texture;
	t->loadFromFile(path1 + type + suffix);
	s->setTexture(*t);
	return s;
}

