#include "RenderManager.h"


RenderManager::RenderManager(ExplorationManager * expM)
{
	_expM = expM;
}

RenderManager::~RenderManager()
{
}

void RenderManager::addToList(sf::Sprite * sp)
{
	_renderList.push_back(sp);
}

void RenderManager::getList()
{
	_renderList.push_back(_expM->getMapManager()->getMapSprite());
	for (auto i : _expM->getRoleManager()->getRenderList()) {
		_renderList.push_back(i);
	}
	for (auto i : _expM->getMenuManager()->getRenderList()) {
		_renderList.push_back(i);
	}
}

void RenderManager::rendering()
{
	getList();
	sf::RenderWindow* window = _expM->getWindow();
	for (auto i : _renderList) {
		window->draw(*i);
	}
	_renderList.clear();
}

