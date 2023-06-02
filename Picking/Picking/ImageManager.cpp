#include "ImageManager.h"

ImageManager* ImageManager::instance = nullptr;

ImageManager::ImageManager() 
{
	PushImage("Tile", (new Bitmap())->Loadbmp(L"../Resource/Tile.bmp"));
}
ImageManager::~ImageManager() {}

void ImageManager::PushImage(string key, Bitmap* image)
{
	imageList[key] = image;
}

Bitmap* ImageManager::GetFromKeyToImage(string key)
{
	if (imageList.find(key) == imageList.end()) return nullptr;
	return imageList[key];
}