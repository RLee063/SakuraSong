#pragma once
#include "Includes.h"
#include "list"
using namespace std;
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void addToList(sf::Sprite* sp);
	void getList();
	void rendering();
private:
	list<sf::Sprite*> _renderList;
};