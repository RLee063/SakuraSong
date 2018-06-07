#pragma once
//texture
#define MAP1_TEXTURE_PATH "src\\picture\\map1.png"
#define BATTLE1_TEXTURE_PATH "src\\picture\\battle1.png"

#define PIKA_TEXTURE_PATH "src\\texture\\pika\\"
#define FIREDRAGON_TEXTURE_PATH "src\\texture\\firedragon\\"
#define TURTOISE_TEXTURE_PATH "src\\texture\\turtoise\\"
#define TUDOU_TEXTURE_PATH "src\\texture\\tudou\\"

#define TERRAIN_TEXTURE_PATH "src\\texture\\terrain\\"
#define MENU1_FRAME_TEXTURE_PATH "src\\texture\\menu\\1.png"
#define MENU2_FRAME_TEXTURE_PATH "src\\texture\\menu\\2.png"
#define BUTTON1_TEXTURE_PATH "src\\texture\\button\\1.png"
#define BUTTON1_SELECTED_TEXTURE_PATH "src\\texture\\button\\1s.png"
#define BUILD_TEXTURE_PATH "src\\texture\\build\\"
//config
#define MAP1_CONFIG_PATH "config\\map1"
#define SAVE_CONFIG_PATH "config\\save"
//font
#define FONT1_PATH "font\\1.ttf"
//magic number

#define WINDOW_HEIGHT 10
#define WINDOW_WIDTH 10
#define WINDOW_HEIGHT_PIX 800
#define WINDOW_WIDTH_PIX 800
#define UNIT_LENGTH WINDOW_HEIGHT_PIX/WINDOW_HEIGHT

#define DELAY 40

#define ANIMATION_DELAY DELAY
#define ROLE_ANIMATION_COUNT 4
#define NPC_MOVE_DELAY_RAND DELAY*20

#define MAIN_MENU_POSITION_X 10
#define MAIN_MENU_POSITION_Y 500
#define MAIN_MENU_HEIGHT 300
#define MAIN_MENU_WEIGHTH 800
#define HERO_STARTPOSITION_X 15
#define HERO_STARTPOSITION_Y 15

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

typedef enum {
	PIKA,
	FIREDRAGON,
	FIREDRAGON2,
	TURTOISE,
	TUDOU
}ROLE;

typedef enum {
	HERO,
	MOVENPC,
	ENEMY,
	STOPNPC
}ROLETYPE;

typedef enum {
	DIRT,
	GRASS,
	WATER
}TERRAIN;

typedef enum {
	NOBUILD,
	B_TREE1,
	B_DEADTREE1,
	B_TREE2,
	B_HOUSE1,
	B_SEA = 9,
	B_GROUND1 = 200,
	B_GROUND2
}BUILD;