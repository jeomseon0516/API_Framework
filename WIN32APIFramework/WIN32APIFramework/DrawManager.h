#pragma once
#include "Singleton.h"
#include "Include.h"

#define DRAW_MANAGER (*DrawManager::GetInstance())

class DrawManager
{
    SINGLETON(DrawManager);
private:

	HDC _hdc;
	HDC _nextHdc;

public:

	void Update() { Rectangle(_hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y); }
	HDC GetHdc()const { return _hdc; }

    ~DrawManager();
};