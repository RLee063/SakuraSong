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

}

void RenderManager::rendering()
{
	sf::RenderWindow* window = _expM->getWindow();
	for (auto i : _renderList) {
		window->draw(*i);
	}
}

