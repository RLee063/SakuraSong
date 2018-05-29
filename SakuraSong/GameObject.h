#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void update(){};
	void invisible();
	void visible();
protected:
	bool _isVisible;
};
