#include "RenderManager.h"
#include "Locator.h"
#include "MapManager.h"
#include "RoleManager.h"
#include "MenuManager.h"
RenderManager::RenderManager()
{
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
	getList();
	sf::RenderWindow* window = Locator::getWindow();
	for (auto i : _renderList) {
		window->draw(*i);
	}
	_renderList.clear();
}

