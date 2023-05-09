#include "DrawManager.h"

SINGLETON_INIT(DrawManager)

DrawManager::DrawManager()
{
	_hdc = GetDC(g_hWnd);
	_nextHdc = GetDC(g_hWnd);
}

DrawManager::~DrawManager() {}