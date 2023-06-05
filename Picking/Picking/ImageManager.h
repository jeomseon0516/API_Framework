#pragma once
#include "Include.h"
#include "Bitmap.h"
#include "Singleton.h"

#define IMAGE_MANAGER GET_SINGLETON(ImageManager)

class ImageManager
{
	SINGLETON(ImageManager);
private:
	map<string, Bitmap*> imageList;
public:
	void PushImage(string key, Bitmap* image);
	Bitmap* GetFromKeyToImage(string key);
};