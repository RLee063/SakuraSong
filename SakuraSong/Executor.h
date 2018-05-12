#pragma once
class Executor
{
public:
	Executor();
	~Executor();
	virtual bool execute() = 0;
};

