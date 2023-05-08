#include "GameManager.h"

SINGLETON_INIT(GameManager)

GameManager::GameManager() {}

void GameManager::PushManagerList(Singleton* manager)
{
    singletonList.push_back(manager);
}