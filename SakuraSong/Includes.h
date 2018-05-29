
#pragma once
//texture
#define MAP1_TEXTURE_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\picture\\map1.png"
#define BATTLE1_TEXTURE_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\picture\\battle1.png"
#define HERO_TEXTURE_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\hero\\"
#define ENEMY_TEXTURE_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\enemy\\"
#define HUOLONG_TEXTURE_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\huolong\\"
#define TERRAIN_TEXTURE_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\src\\texture\\terrain\\"
//config
#define MAP1_CONFIG_PATH "D:\\_Windows_saving\\GitHub\\SakuraSong\\SakuraSong\\config\\map1"

//magic number
#define UNIT_LENGTH 80
#define ROLE_ANIMATION_COUNT 4
//typedef

#include "SFML\Graphics.hpp"
#define MAP_HEIGHT 10
#define MAP_WIDTH 10
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
#define WALK_LENGTH WINDOW_HEIGHT/MAP_HEIGHT
#define ANIMATION_DELAY 40

#define MAIN_MENU_POSITION_X 0
#define MAIN_MENU_POSITION_Y 500
#define MAIN_MENU_HEIGHT 300
#define MAIN_MENU_WEIGHTH 800

typedef enum {
	DIRT,
	GRASS
}TERRAIN;

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NODIRECTION
}DIRECTION;

typedef enum {
	NOFUNCTION,
	DETECT
}FUNCTION;

#pragma once
#include "Locator.h"
#include "MapManager.h"
#include "MenuManager.h"
#include "RenderManager.h"
#include "RoleManager.h"
#include "Control.h"
#include "Menu.h"
#include "Role.h"
#include "BattleManager.h"
#include "Scene.h"
#include "Implement.h"
#include "State.h"
#include "World.h"
#include "Creator.h"
#include "Terrain.h"
#include "Command.h"
#include <iostream>
#include <fstream>