#include "BackGround.h"
#include "testInclude.h"


BackGround::BackGround(char * tPath)
{
	_backT.loadFromFile(tPath);
	_backS.setTexture(_backT);
}


BackGround::~BackGround()
{
}

void BackGround::update()
{
	Locator::getWindow()->draw(_backS);
}

MapBackGround::MapBackGround(char * tPath)
	:BackGround(tPath)
{
}

void MapBackGround::update()
{
	BackGround::update();
}
