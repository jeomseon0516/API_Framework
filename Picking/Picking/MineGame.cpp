#include "MineGame.h"
#include "Tile.h"

MineGame::MineGame() {}
MineGame::~MineGame() { Destroy(); }

MineGame* MineGame::Start()
{
	srand(time(NULL));

	transform = Transform(Vector2(COUNT_X, COUNT_Y) * TILE_SIZE * 0.5f, Vector2(COUNT_X, COUNT_Y) * TILE_SIZE);

	const int maxIndex = COUNT_X * COUNT_Y;
	int boomCount = BOOM_COUNT;
	tileList.resize(maxIndex);

	// Ÿ���� �̸� ���ص� ������ŭ ��ġ ��Ű�� ���� ���ʺ��� ������ ������ŭ ��ġ ��Ų��.
	for (int i = 0; i < maxIndex; ++i)
		tileList[i] = (new Tile())->Start(this, int(TILE_SIZE * 0.5f + TILE_SIZE * (i % COUNT_X)),
												int(TILE_SIZE * 0.5f + TILE_SIZE * (i / COUNT_X)), boomCount-- > 0);

	// 5000�� ���� ��Ų��.	
	for (int i = 0; i < 5000; ++i)
	{
		int randIndex1 = rand() % tileList.size();
		int randIndex2 = rand() % tileList.size();

		Tile* temp = tileList[randIndex1];
		Vector2 tempPosition = tileList[randIndex1]->transform.position;

		tileList[randIndex1]->transform.position = tileList[randIndex2]->transform.position;
		tileList[randIndex1] = tileList[randIndex2];

		tileList[randIndex2]->transform.position = tempPosition;
		tileList[randIndex2] = temp;
	}

	// ��ź�� Ÿ���� ������ ������ Ÿ���� �ֺ��� ��� ���ڰ� �ִ��� Ȯ��
	for (int i = 0; i < tileList.size(); ++i)
	{
		if (tileList[i]->GetIsBoom()) continue; // �ڱ� �ڽ��� ���ڶ�� ����

		for (int j = 0; j < 9; ++j)
		{
			if (CheckEdge(i, j)) continue; // ���� Ÿ���� �����ڸ��� ��� ����ó��

			int index = ConvertFrom2DToIndex((i % COUNT_X - 1) + j % 3, ((i / COUNT_X) + j / 3) - 1);

			if (i != index && tileList[index]->GetIsBoom()) // �ڱ� �ڽ��� üũ�� �ʿ䰡 �����Ƿ�
				tileList[i]->SetAroundBoomCount(tileList[i]->GetAroundBoomCount() + 1);
		}
	}

	return this;
}

inline void MineGame::Update()
{
	for (int i = 0; i < tileList.size(); ++i)
		tileList[i]->Update();
}

inline void MineGame::Render()
{
	for (int i = 0; i < tileList.size(); ++i)
		tileList[i]->Render();
}

void MineGame::Destroy()
{
	for (int i = 0; i < tileList.size(); ++i)
	{
		delete tileList[i];
		tileList[i] = nullptr;
	}

	tileList.clear();
}

void MineGame::GameOver()
{
	for (int i = 0; i < tileList.size(); ++i)
		tileList[i]->OpenNode();
}

void MineGame::OpenNodes(Tile* tile)
{
	Vector2 position = tile->transform.position;

	int pivotIndex = ConvertFrom2DToIndex((position.x - TILE_SIZE * 0.5f) / TILE_SIZE, 
										 ((position.y - TILE_SIZE * 0.5f) / TILE_SIZE));

	for (int i = 0; i < 9; ++i)
	{
		if (CheckEdge(pivotIndex, i)) continue;

		int index = ConvertFrom2DToIndex((pivotIndex % COUNT_X - 1) + i % 3, 
										((pivotIndex / COUNT_X) + i / 3) - 1);

		if (pivotIndex != index && !tileList[index]->GetIsBoom() && !tileList[index]->GetIsCurrent() && !tileList[index]->GetIsCheck())
		{
			tileList[index]->OpenNode();

			if (tileList[index]->GetAroundBoomCount() == 0)
				OpenNodes(tileList[index]);
		}
	}
}

bool MineGame::CheckEdge(const int pivotIndex, const int index)
{
	return pivotIndex % COUNT_X == COUNT_X - 1 && index % 3 == 2 ||
		   pivotIndex % COUNT_X == 0		   && index % 3 == 0 ||
		   pivotIndex / COUNT_X == COUNT_Y - 1 && index / 3 == 2 ||
		   pivotIndex / COUNT_X == 0		   && index / 3 == 0;
}

int MineGame::ConvertFrom2DToIndex(const int x, const int y)
{
	return y * COUNT_X + x;
}