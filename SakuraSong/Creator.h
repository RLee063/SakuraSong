#pragma once

class Scene;

class Creator
{
public:
	Creator();
	~Creator();
	Scene * createMap1Scene();
private:
	Scene * _map1Scene;
};

