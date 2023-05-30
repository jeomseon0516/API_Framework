#include "ImageManager.h"
#include "Bitmap.h"

ImageManager::ImageManager()  
{
    m_mapImageList.insert(
        make_pair("BackGround", (new Bitmap)->LoadBmp(L"../Resource/Stage/BackGround.bmp")));
    m_mapImageList.insert(
        make_pair("Buffer", (new Bitmap)->LoadBmp(L"../Resource/Stage/Buffer.bmp")));
    m_mapImageList.insert(
        make_pair("Character", (new Bitmap)->LoadBmp(L"../Resource/Sprite/Player.bmp")));
}
ImageManager::~ImageManager() {}