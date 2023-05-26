#pragma once
#include "Include.h"
#include "Singleton.h"
#include "Bitmap.h"

#define IMAGE_MANAGER (*ImageManager::GetInstance())

class ImageManager
{
    SINGLETON(ImageManager);
private:
    map<string, Bitmap*> m_mapImageList;
public:
    map<string, Bitmap*>* GetImageList() { return &m_mapImageList; }
public:
    ~ImageManager();
};