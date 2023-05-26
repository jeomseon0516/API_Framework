#include "DrawManager.h"

DrawManager::DrawManager() : _hdc(GetDC(g_hWnd)), m_imageList(IMAGE_MANAGER->GetImageList()){}

DrawManager::~DrawManager() {}