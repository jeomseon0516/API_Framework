#pragma once
#include "ImageManager.h"
#include "Include.h"

#define DRAW_MANAGER (*DrawManager::GetInstance())

class DrawManager
{
    SINGLETON(DrawManager);
private:
    map<string, Bitmap*>* m_imageList;
	HDC _hdc;
    HDC _memDC;
public:

	void Update() 
    {
        BitBlt(_hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, _memDC, 0, 0, SRCCOPY);
    }

	HDC GetHdc()const { return _hdc; }
    HDC GetMemDC()const { return _memDC; }

    ~DrawManager();
};