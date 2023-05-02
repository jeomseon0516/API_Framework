#include "MainUpdate.h"

void MainUpdate::Start()
{
	_character = new Character();
}

void MainUpdate::Update()
{
	INPUTMANAGER->Update();
	OBJECTMANAGER->Update();
}
