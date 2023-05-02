#include "DrawManager.h"

void DrawManager::Update()
{
	RECT bufferRT; // 새로 그릴 화면의 크기
	HDC memDC, tmpDC;
	HBITMAP BackBit, oldBackBit;
	//_hdc = BeginPaint(g_hWnd, &ps);

	GetClientRect(g_hWnd, &bufferRT);
	//InvalidateRect(g_hWnd, &bufferRT, true);

	_hdc = _nextHdc;
	_nextHdc = GetDC(g_hWnd);
}

DrawManager::DrawManager()
{
	_hdc = GetDC(g_hWnd);
	_nextHdc = GetDC(g_hWnd);
}
