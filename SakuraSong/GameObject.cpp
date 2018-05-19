#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::invisible()
{
	_isVisible = 0;
}

void GameObject::visible()
{
	_isVisible = 1;
}
