#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>

using namespace std;

// .. CONSTANTS ..

#define CNT_X 5
#define CNT_Y 5

enum COLOR : unsigned char
{
	BLACK		  = 0,
	DARK_BLUE	  = 1,
	DARK_GREEN	  = 2,
	DARK_SKY_BLUE = 3,
	DARK_RED	  = 4,
	DARK_PURPLE	  = 5,
	DARK_YELLOW   = 6,
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

void SetCursorPosition(const float& _x, const float& _y);
void SetColor(int color);
void Text(const float& _x, const float& _y, const string& _str, const int _color = WHITE);

typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}
}Vector3;

typedef struct tagTile
{
	Vector3 position[3];
	string tile[3];
	Vector3 numberPosition;
	int index;
	int number;
	bool isCheck;

	void Render(const int _color = WHITE, bool isCurrent = false)
	{
		SetColor(GRAY);

		int color = !isCheck || isCurrent ? _color : BLUE;

		for (int i = 0; i < 3; ++i)
			Text(position[i].x, position[i].y, tile[i], color);

		char buffer[4] = { 0 };

		_itoa_s(number, buffer, 10);
		Text(numberPosition.x, numberPosition.y, buffer, color);
	}

	tagTile() : index(0), number(0), isCheck(false) {}
}Tile;

typedef struct tagInfo
{
	Vector3 position;

	tagInfo() : position(Vector3(0, 0)) {}
	tagInfo(Vector3 _position) : position(_position) {}
}Info;

int main(void)
{
	srand((unsigned int)time(NULL));
	vector<Tile> tileList;

	int maxIndex = CNT_Y * CNT_X;
	tileList.resize(maxIndex);

	Vector3 position;
	position.x = 5;
	position.y = 5;

	Vector3 scale;
	scale.x = 5;
	scale.y = 3;

	for (int i = 0; i < maxIndex; ++i)

	for (int i = 0; i < maxIndex; ++i)
	{
		Tile tile;

		int x = i % CNT_X;
		int y = i / CNT_X;

		for (int j = 0; j < 3; ++j)
			tile.position[j] = Vector3(position.x - scale.x * 0.5f + scale.x * x + scale.x,
									   position.y - scale.y * 0.5f + scale.y * y + j);

		tile.tile[0] = "┌───┐";
		tile.tile[1] = "│   │";
		tile.tile[2] = "└───┘";

		tile.number = tile.index = i;
		tile.numberPosition = Vector3(position.x - 1 + scale.x * x + scale.x,
									  position.y - scale.y * 0.5f + scale.y * y + 1);

		tileList[i] = tile;
	}

	for (int i = 0; i < 1000; ++i)
	{
		int randIndex  = rand() % maxIndex;
		int randIndex2 = rand() % maxIndex;
		int temp = tileList[randIndex].number;
		tileList[randIndex].number  = tileList[randIndex2].number;
		tileList[randIndex2].number = temp;
	}

	Info cursor;

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();
			system("cls");

			if		(GetAsyncKeyState(VK_LEFT))
				--cursor.position.x;
			else if (GetAsyncKeyState(VK_RIGHT))
				++cursor.position.x;
			else if (GetAsyncKeyState(VK_UP))
				--cursor.position.y;
			else if (GetAsyncKeyState(VK_DOWN))
				++cursor.position.y;
			
			bool check = false;

			if (GetAsyncKeyState(VK_SPACE))
				check = true;

			if (cursor.position.x < 0)
				cursor.position.x = 0;

			if (cursor.position.y < 0)
				cursor.position.y = 0;

			if (cursor.position.x >= CNT_X)
				cursor.position.x = CNT_X - 1;

			if (cursor.position.y >= CNT_Y)
				cursor.position.y = CNT_Y - 1;

			int myIndex = int(cursor.position.y * CNT_X + cursor.position.x);

			for (Tile& tile : tileList)
			{
				bool isCurrent = tile.index == myIndex;

				if (isCurrent && check)
					tile.isCheck = !tile.isCheck;

				tile.Render(isCurrent ? RED : WHITE, isCurrent);
			}

			Sleep(20);  
		}
	}

	return 0;
}

void SetCursorPosition(const float& _x, const float& _y)
{
	COORD pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Text(const float& _x, const float& _y, const string& _str, const int _color)
{
	SetColor(_color);
	SetCursorPosition(_x, _y);
	cout << _str << endl;
}

void SetColor(int _color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}