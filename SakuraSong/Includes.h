#pragma once
#include "SFML\Graphics.hpp"
#define MAP_HEIGHT 10
#define MAP_WIDTH 10
#define MAP_HEIGHT_PIX 800
#define MAP_WIDTH_PIX 800
#define WALK_LENGTH MAP_HEIGHT_PIX/MAP_HEIGHT
#define ANIMATION_DELAY 70
typedef enum {
	GROUND,
	WATER
}MAP;

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
