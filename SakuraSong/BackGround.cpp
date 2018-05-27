#include "BackGround.h"
#include "testInclude.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::update()
{
	
}

MapBackGround::MapBackGround(char * tPath)
{
	_backT.loadFromFile(tPath);
	_backS.setTexture(_backT);
}

void MapBackGround::update()
{
	Locator::getWindow()->draw(_backS);
}
