#pragma once
#include "Stage.h"
#include "MineGame.h"

class Main : public Stage
{
private:
	MineGame* mineGame;
public:
	// Stage을(를) 통해 상속됨
	void Start() override;
	void Update() override 
	{
		mineGame->Update();
	}
	void Render() override 
	{
		mineGame->Render();
	}

public:
	 Main();
	~Main();
};

