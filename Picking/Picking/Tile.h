#pragma once
#include "Object.h"
#include "ImageManager.h"

#define BOOM Frame(Locomotion(1, 0), 5)
#define DEFAULT Frame(Locomotion(1, 1), 1)
#define RED Frame(Locomotion(1, 0), 1)

class Tile : public Object
{
private:
	bool isCurrent;
	bool isBoom;
	Bitmap* image;
	int positionX, positionY;
	Frame imageFrame;
	Vector2 count;

public:
	Tile* Start(int _countX, int _countY, bool _isBoom);
	Tile* Start() override;
	void Update() override
	{
		POINT cursorPoint;

		GetCursorPos(&cursorPoint);
		ScreenToClient(g_hWnd, &cursorPoint);

		if (!isCurrent && GetAsyncKeyState(VK_LBUTTON))
		{
			isCurrent = transform.position.x - transform.size.x * 0.5f < cursorPoint.x &&
						transform.position.x + transform.size.x * 0.5f > cursorPoint.x &&
						transform.position.y - transform.size.y * 0.5f < cursorPoint.y &&
						transform.position.y + transform.size.y * 0.5f > cursorPoint.y;
		}

		if (GetAsyncKeyState(VK_TAB))
			isCurrent = true;

		if (isCurrent)
			imageFrame = isBoom ? BOOM : RED;
	}
	void Render() override
	{
		TransparentBlt(g_hdc,
			int(transform.position.x - transform.size.x * 0.5f),
			int(transform.position.y - transform.size.y * 0.5f),
			(int)transform.size.x,
			(int)transform.size.y,
			image->GetMemDC(),
			int(imageFrame.frameX * transform.size.x),
			int(imageFrame.locomotion.frameY * transform.size.x),
			(int)transform.size.x,
			(int)transform.size.y,
			RGB(255, 0, 255));
	}
	void Destroy() override;

public:
	Tile();
	~Tile();
};

