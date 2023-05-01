#include "MainUpdate.h"

void MainUpdate::Start()
{
	_character = new Character();
	OBJECTMANAGER->ObjectsInit();
}

void MainUpdate::Update()
{
	INPUTMANAGER->Update();
	OBJECTMANAGER->Update();
}
