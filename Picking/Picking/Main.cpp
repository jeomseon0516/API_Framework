#include "Main.h"

Main::Main() {}
Main::~Main() {}

void Main::Start()
{
	srand(time(NULL));
	// const int wx = WIN_SIZE_X / TILE_SIZE, wy = WIN_SIZE_Y / TILE_SIZE;
	const int maxIndex = COUNT_X * COUNT_Y;
	int boomCount = BOOM_COUNT;

	for (int i = 0; i < maxIndex; ++i)
		tileList.push_back((new Tile())->Start(int(TILE_SIZE * 0.5f + TILE_SIZE * (i % COUNT_X)), 
											   int(TILE_SIZE * 0.5f + TILE_SIZE * (i / COUNT_X)), boomCount-- > 0 ? true : false));
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
}