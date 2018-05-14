#pragma once
#include "Includes.h"
#include "ExplorationManager.h"
class Decision
{
public:
	Decision(ExplorationManager * expM);
	~Decision();
	virtual bool decide() = 0;
	ExplorationManager* _expManager;
};

class KeyDown : public Decision{
public:
	KeyDown(int code, ExplorationManager * expM);
	bool decide();
private:
	int _code;
};

