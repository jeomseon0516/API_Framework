#pragma once
#include "Include.h"
#include "Main.h"

class MainUpdate
{
private:
	Stage* stage;
public:

	void Start();
	void Update()
	{
		// Rectangle(g_hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);
		
		stage->Update();
		stage->Render();
	}

public:
	 MainUpdate();
	~MainUpdate();
};

