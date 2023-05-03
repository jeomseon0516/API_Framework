#include "MainUpdate.h"

void MainUpdate::Start()
{
	_character = new Character();
	(new Enemy())->SetTarget(_character);
}

void MainUpdate::Update()
{
	DRAWMANAGER->Update();
	COLLISIONMANAGER->Update();
	INPUTMANAGER->Update();
	OBJECTMANAGER->Update();
}
