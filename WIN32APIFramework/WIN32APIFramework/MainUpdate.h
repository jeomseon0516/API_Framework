#pragma once
#include "Include.h"

#define SPEED 0.1F

struct Vector2
{
	float x, y;
};

class MainUpdate
{
private:
	HDC m_hdc;

	float startX, startY;
	float endX, endY;
	float sizeX, sizeY;

public:
	void Start();
	void Update();
	void Render();
	void Destroy();
	 
 	 MainUpdate() {}
	~MainUpdate() {}
};