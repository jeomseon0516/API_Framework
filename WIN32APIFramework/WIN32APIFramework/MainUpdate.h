#pragma once
#include "Include.h"
#include "PlayerManager.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "DrawManager.h"
#include "ObjectPoolManager.h"
#include "Main.h"

class MainUpdate
{
public:
    void Start();

    void Update()
    {
        DRAW_MANAGER->Update();
        GAME_MANAGER->Update();

#ifdef DEBUG
        list<Object*>* bulletList = GET_SINGLETON(ObjectPoolManager)->GetGameObjectList("NormalBullet");

        if (bulletList)
        {
            wstring str = to_wstring(bulletList->size());
            TextOut(DRAW_MANAGER->GetHdc(), 50, 50, str.c_str(), static_cast<int>(str.length()));
        }
#endif
    }

    MainUpdate();
    ~MainUpdate();
};