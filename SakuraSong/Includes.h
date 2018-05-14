#pragma once
#include "SFML\Graphics.hpp"
#define MAP_HEIGHT 10
#define MAP_WIDTH 10

typedef enum {
	GROUND,
	HERO
}MAP;

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NODIRECTION
}DIRECTION;

typedef struct _position {
	int x;
	int y;
}POSITION, PPOSITION;

typedef enum {
	NOFUNCTION,
	DETECT
}FUNCTION;