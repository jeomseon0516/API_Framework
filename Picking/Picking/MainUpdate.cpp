#include "MainUpdate.h"

MainUpdate::MainUpdate() {}
MainUpdate::~MainUpdate() {}

void MainUpdate::Start()
{
	stage = new Main();
	stage->Start();
}