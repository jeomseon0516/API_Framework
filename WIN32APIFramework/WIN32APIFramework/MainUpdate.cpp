#include "MainUpdate.h"

void MainUpdate::Start()
{
	// ..초기화
	DRAWMANAGER;
	COLLISIONMANAGER;
	INPUTMANAGER;
	OBJECTMANAGER;
	// (new Enemy())->SetTarget(_character);
}

void MainUpdate::Update()
{
	DRAWMANAGER->Update();
	COLLISIONMANAGER->Update();
	INPUTMANAGER->Update();
	OBJECTMANAGER->Update();
}
