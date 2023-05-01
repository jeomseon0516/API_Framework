#pragma once
#include "Singleton.h"

class GameManager
{
private:
	friend class Singleton<GameManager>;

	virtual void Update();

private:
	GameManager() {}
};

