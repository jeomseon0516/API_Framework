#pragma once
#include "Singleton.h"

#define DRAWMANAGER DrawManager::GetInstance()

class DrawManager : public Singleton<DrawManager>
{
private:
	friend class Singleton<DrawManager>;

	HDC _hdc;
	HDC _nextHdc;

public:

	HDC GetHdc() { return _hdc; }
	virtual void Update();

private:
	DrawManager();
};

