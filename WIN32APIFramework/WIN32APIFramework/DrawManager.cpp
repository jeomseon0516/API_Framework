#include "DrawManager.h"

DrawManager::DrawManager() : m_imageList(IMAGE_MANAGER->GetImageList())
{
    _hdc = GetDC(g_hWnd);
    _memDC = CreateCompatibleDC(_hdc);

    HBITMAP hBitmap = CreateCompatibleBitmap(_hdc, WIN_SIZE_X, WIN_SIZE_Y);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(_memDC, hBitmap);
}

DrawManager::~DrawManager() {}