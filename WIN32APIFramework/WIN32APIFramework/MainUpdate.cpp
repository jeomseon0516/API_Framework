#include "MainUpdate.h"

void MainUpdate::Start()
{
	_character = new Character();
	(new Enemy())->SetTarget(_character);
}

void MainUpdate::Update()
{
	INPUTMANAGER->Update();
	OBJECTMANAGER->Update();
}
