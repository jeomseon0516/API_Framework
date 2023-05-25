#pragma once
#include "Include.h"
#include "Singleton.h"

#define GAME_MANAGER (*GameManager::GetInstance())

class GameManager
{
    SINGLETON(GameManager);
private:
    vector<Singleton*> singletonList; // 싱글톤 생성시 자동으로 싱글톤 리스트에 담겨져 호출된다.

public:
    void Update()
    {
        for (int i = 0; i < singletonList.size(); ++i)
            singletonList[i]->SingletonUpdate();
    }

    void PushManagerList(Singleton* manager);

    ~GameManager();
};