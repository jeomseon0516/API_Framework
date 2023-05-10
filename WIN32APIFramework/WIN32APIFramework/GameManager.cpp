#include "GameManager.h"

GameManager::GameManager() {}
GameManager::~GameManager() {}

void GameManager::PushManagerList(Singleton* manager)
{
    singletonList.push_back(manager);
}