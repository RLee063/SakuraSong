#include "BackGround.h"
#include "Includes.h"


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
