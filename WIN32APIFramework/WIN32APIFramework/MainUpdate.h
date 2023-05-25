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

        if (bulletList && !bulletList->empty())
        {
            char* bulletBuffer = new char[128];

            _itoa((int)bulletList->size(), bulletBuffer, 10);

            string str(bulletBuffer);

            delete[] bulletBuffer;
            bulletBuffer = nullptr;

            wchar_t* t = new wchar_t[(int)str.size()];
            mbstowcs(t, str.c_str(), (int)str.size());

            TextOut(DRAW_MANAGER->GetHdc(), 50, 50, (LPCWSTR)t, (int)str.size());
        }
#endif
    }

    MainUpdate();
    ~MainUpdate();
};