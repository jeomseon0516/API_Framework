#pragma once
#include "Include.h"
#include "Bitmap.h"

#define IMAGE_MANAGER ImageManager::GetInstance()

class ImageManager
{
private:
	map<string, Bitmap*> imageList;
public:
	void PushImage(string key, Bitmap* image);
	Bitmap* GetFromKeyToImage(string key);

private:
	static ImageManager* instance;
public:
	static ImageManager* GetInstance()
	{
		return instance ? instance : instance = new ImageManager;
	}
private:
	ImageManager();
public:
	~ImageManager();
};