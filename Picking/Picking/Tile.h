#pragma once
#include "Object.h"
#include "ImageManager.h"
#include "MineGame.h"

#define WHITE	 Frame(Locomotion(1, 0), 0)
#define RED		 Frame(Locomotion(1, 0), 1)
#define ORANGE	 Frame(Locomotion(1, 0), 2)
#define YELLOW	 Frame(Locomotion(1, 0), 3)
#define GREEN	 Frame(Locomotion(1, 1), 0)
#define SKY_BLUE Frame(Locomotion(1, 1), 1)
#define BLUE     Frame(Locomotion(1, 1), 2)
#define PURPLE   Frame(Locomotion(1, 1), 3)

#define BOOM     Frame(Locomotion(1, 0), 5)
#define FLAG     Frame(Locomotion(1, 1), 8)
#define DEFAULT  SKY_BLUE

#define ZERO	 RED
#define ONE      Frame(Locomotion(1, 0), 4)
#define TWO      Frame(Locomotion(1, 1), 4)
#define THREE    Frame(Locomotion(1, 1), 5)
#define FOUR     Frame(Locomotion(1, 0), 6)
#define FIVE     Frame(Locomotion(1, 1), 6)
#define SIX      Frame(Locomotion(1, 0), 7)
#define SEVEN    Frame(Locomotion(1, 1), 7)
#define EIGHT    Frame(Locomotion(1, 0), 8)

class Tile : public Object
{
private:
	Frame numberMap[9];
	bool isCurrent, isBoom , isCheck;
	char aroundBoomCount;
	MineGame* mineGame;
	Bitmap* image;
	Frame imageFrame;

public:
	Tile* Start(MineGame* _mineGame, int _countX, int _countY, bool _isBoom);
	Tile* Start() override;
	void Update() override
	{
		POINT cursorPoint;

		GetCursorPos(&cursorPoint);
		ScreenToClient(g_hWnd, &cursorPoint);

		if (GetAsyncKeyState(VK_TAB))
			OpenNode();

		if (!isCurrent && GetAsyncKeyState(VK_LBUTTON) && !isCheck)
		{
			isCurrent = CheckCursorCollision(cursorPoint);

			if (isCurrent)
			{
				if (isBoom)
					mineGame->GameOver();
				else
				{
					mineGame->OpenNodes(this);
					imageFrame = numberMap[aroundBoomCount];
				}
			}
		}

		if (!isCurrent && GetAsyncKeyState(VK_RBUTTON) && CheckCursorCollision(cursorPoint))
			imageFrame = (isCheck = !isCheck) ? FLAG : DEFAULT;
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

	bool CheckCursorCollision(POINT cursorPoint)
	{
		return transform.position.x - transform.size.x * 0.5f < cursorPoint.x &&
			   transform.position.x + transform.size.x * 0.5f > cursorPoint.x &&
			   transform.position.y - transform.size.y * 0.5f < cursorPoint.y &&
			   transform.position.y + transform.size.y * 0.5f > cursorPoint.y;
	}

	bool GetIsCheck()const { return isCheck; }

	bool GetIsCurrent()const { return isCurrent; }
	void SetIsCurrent(const bool _isCurrent) { isCurrent = _isCurrent; }
	
	bool GetIsBoom()const	 { return isBoom; }

	int  GetAroundBoomCount()const { return aroundBoomCount; }
	void SetAroundBoomCount(const int _aroundBoomCount) { aroundBoomCount = _aroundBoomCount; }

	void OpenNode();

public:
	 Tile();
	~Tile();
};

