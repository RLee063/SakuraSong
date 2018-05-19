#pragma once
#include "Includes.h"
#include "ExplorationManager.h"
#include "list"
class RenderManager
{
public:
	RenderManager(ExplorationManager* expM);
	~RenderManager();
	void addToList(sf::Sprite* sp);
	void getList();
	void rendering();
private:
	ExplorationManager* _expM;
	list<sf::Sprite*> _renderList;
};

