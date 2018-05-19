#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void update() = 0;
	void invisible();
	void visible();
protected:
	bool _isVisible;
};
