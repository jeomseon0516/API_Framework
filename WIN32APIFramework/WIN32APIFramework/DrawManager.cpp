#include "DrawManager.h"

void DrawManager::Update()
{
	Rectangle(_hdc, 0, 0, 1500, 720);
}

DrawManager::DrawManager()
{
	_hdc = GetDC(g_hWnd);
	_nextHdc = GetDC(g_hWnd);
}
