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
public:

	void Update() 
    {
        BitBlt(_hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, (*m_imageList)["Buffer"]->GetMemDC(), 0, 0, SRCCOPY);
    }
	HDC GetHdc()const { return _hdc; }

    ~DrawManager();
};