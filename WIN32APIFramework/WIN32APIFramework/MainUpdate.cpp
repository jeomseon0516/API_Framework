#include "MainUpdate.h"

MainUpdate::MainUpdate() {}
MainUpdate::~MainUpdate() {}

void MainUpdate::Start()
{
	// ..초기화
    m_imageList = IMAGE_MANAGER->GetImageList();
	GAME_MANAGER;
    INPUT_MANAGER;
    PLAYER_MANAGER;
    SCENE_MANAGER->SetScene(new Main());
}