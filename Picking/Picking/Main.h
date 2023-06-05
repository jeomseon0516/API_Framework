#pragma once
#include "Stage.h"
#include "Tile.h"

#define BOOM_COUNT 100

class Main : public Stage
{
private:
	vector<Tile*> tileList;
public:
	// Stage을(를) 통해 상속됨
	void Start() override;
	void Update() override 
	{
		for (int i = 0; i < tileList.size(); ++i)
			tileList[i]->Update();
	}
	void Render() override 
	{
		for (int i = 0; i < tileList.size(); ++i)
			tileList[i]->Render();
	}

public:
	 Main();
	~Main();
};

