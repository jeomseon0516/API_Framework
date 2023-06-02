#pragma once
#include "Object.h"
#include "ImageManager.h"

class Tile : public Object
{
private:
	bool isCurrent;
	Bitmap* image;
	int positionX, positionY;

public:
	Tile* Start(int _countX, int _countY);
	Tile* Start() override;
	void Update() override 
	{
		POINT cursorPoint;

		GetCursorPos(&cursorPoint);
		ScreenToClient(g_hWnd, &cursorPoint);

		/*float x = cursorPoint.x - transform.position.x;
		float y = cursorPoint.y - transform.position.y;

		float distance = sqrtf(x * x + y * y);*/

		if (!isCurrent)
		{
			isCurrent = transform.position.x - transform.size.x * 0.5f < cursorPoint.x &&
						transform.position.x + transform.size.x * 0.5f > cursorPoint.x &&
						transform.position.y - transform.size.y * 0.5f < cursorPoint.y &&
						transform.position.y + transform.size.y * 0.5f > cursorPoint.y;
		}
	}
	void Render() override 
	{
		TransparentBlt(g_hdc,
			int(transform.position.x - transform.size.x * 0.5f),
			int(transform.position.y - transform.size.y * 0.5f),
			(int)transform.size.x,
			(int)transform.size.y,
			image->GetMemDC(),
			1 * transform.size.x,
			isCurrent ? 0 : 1 * transform.size.x,
			(int)transform.size.x,
			(int)transform.size.y,
			RGB(255, 0, 255));
	}
	void Destroy() override;

public:
	 Tile();
	~Tile();
};

