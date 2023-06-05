#include "ImageManager.h"

ImageManager::ImageManager() 
{
	PushImage("Tile", (new Bitmap())->Loadbmp(L"../Resource/Tile.bmp"));
}

void ImageManager::PushImage(string key, Bitmap* image)
{
	imageList[key] = image;
}

Bitmap* ImageManager::GetFromKeyToImage(string key)
{
	if (imageList.find(key) == imageList.end()) return nullptr;
	return imageList[key];
}