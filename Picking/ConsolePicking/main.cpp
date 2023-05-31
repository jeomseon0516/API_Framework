#include <iostream>
#include <Windows.h>

using namespace std;

#define CNT_X 10
#define CNT_Y 6

enum COLOR : unsigned char
{
	BLACK		  = 0,
	DARK_BLUE	  = 1,
	DARK_GREEN	  = 2,
	DARK_SKY_BLUE = 3,
	DARK_RED	  = 4,
	DARK_PURPLE	  = 5,
	DARK_YELLOW	  = 6,
	GRAY		  = 7,
	DARK_GRAY	  = 8,
	BLUE		  = 9,
	GREEN		  = 10,
	SKY_BLUE	  = 11,
	RED			  = 12,
	PURPLE		  = 13,
	YELLOW		  = 14,
	WHITE		  = 15
};

typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}
}Vector3;

void SetCursorPosition(const float& _x, const float& _y);
void SetColor(int color);
void Text(const float& _x, const float& _y, const string& _str);

int main(void)
{
	Vector3 position;
	position.x = 55;
	position.y = 13;

	Vector3 scale;
	scale.x = 5;
	scale.y = 3;

	Vector3 myPosition;

	ULONGLONG time = GetTickCount64();

	while (true)
	{ 
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();
			system("cls");

			if		(GetAsyncKeyState(VK_LEFT))
				--myPosition.x;
			else if (GetAsyncKeyState(VK_RIGHT))
				++myPosition.x;
			else if (GetAsyncKeyState(VK_UP))
				--myPosition.y;
			else if (GetAsyncKeyState(VK_DOWN))
				++myPosition.y;

			int myIndex = myPosition.y * CNT_X + myPosition.x;

			for (int y = 0; y < CNT_Y; ++y)
			{
				for (int x = 0; x < CNT_X; ++x)
				{
					SetColor(GRAY);

					Text(position.x - scale.x * 0.5f + scale.x * x + scale.x, position.y - scale.y * 0.5f + scale.y * y,	 "┌───┐");
					Text(position.x - scale.x * 0.5f + scale.x * x + scale.x, position.y - scale.y * 0.5f + scale.y * y + 1, "│   │");
					Text(position.x - scale.x * 0.5f + scale.x * x + scale.x, position.y - scale.y * 0.5f + scale.y * y + 2, "└───┘");

					int index = y * CNT_X + x;

					char buffer[4];

					_itoa_s(index, buffer, 10);
					SetColor(myIndex == index ? PURPLE : DARK_GRAY);

					Text(position.x - 1 + scale.x * x + scale.x, position.y - scale.y * 0.5f + scale.y * y + 1, buffer);
				}
			}

			Sleep(50);
		}
	}


	return 0;
}

void SetCursorPosition(const float& _x, const float& _y)
{
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Text(const float& _x, const float& _y, const string& _str)
{
	SetCursorPosition(_x, _y);
	cout << _str << endl;
}

void SetColor(int _color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}
