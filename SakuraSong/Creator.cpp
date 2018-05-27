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
