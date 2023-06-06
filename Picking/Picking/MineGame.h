#pragma once
#include "Object.h"

#define BOOM_COUNT 99

class Tile;

class MineGame : public Object
{
private:
	vector<Tile*> tileList;
public:
	MineGame* Start();
	inline virtual void Update();
	inline virtual void Render();

	virtual void Destroy();
	void GameOver();
	void OpenNodes(Tile* tile);

	bool CheckEdge(const int pivotIndex, const int index);
	int ConvertFrom2DToIndex(const int x, const int y);

public:
	 MineGame();
	~MineGame();
};