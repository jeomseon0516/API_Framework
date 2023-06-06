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

	// 타일을 미리 정해둔 개수만큼 배치 시키고 가장 앞쪽부터 지뢰의 개수만큼 배치 시킨다.
	for (int i = 0; i < maxIndex; ++i)
		tileList[i] = (new Tile())->Start(this, int(TILE_SIZE * 0.5f + TILE_SIZE * (i % COUNT_X)),
												int(TILE_SIZE * 0.5f + TILE_SIZE * (i / COUNT_X)), boomCount-- > 0);

	// 5000번 셔플 시킨다.	
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

	// 폭탄인 타일을 제외한 각자의 타일이 주변에 몇개의 지뢰가 있는지 확인
	for (int i = 0; i < tileList.size(); ++i)
	{
		if (tileList[i]->GetIsBoom()) continue; // 자기 자신이 지뢰라면 예외

		for (int j = 0; j < 9; ++j)
		{
			if (CheckEdge(i, j)) continue; // 현재 타일이 가장자리인 경우 예외처리

			int index = ConvertFrom2DToIndex((i % COUNT_X - 1) + j % 3, ((i / COUNT_X) + j / 3) - 1);

			if (i != index && tileList[index]->GetIsBoom()) // 자기 자신은 체크할 필요가 없으므로
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