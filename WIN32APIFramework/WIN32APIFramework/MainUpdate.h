#pragma once
#include "Include.h"
#include "PlayerManager.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "DrawManager.h"
#include "ImageManager.h"
#include "ObjectPoolManager.h"
#include "Main.h"

class MainUpdate
{
private:
    map<string, Bitmap*>* m_imageList;
public:
    void Start();

    void Update()
    {
        BitBlt(DRAW_MANAGER->GetMemDC(), 0, 0, WIN_SIZE_X, WIN_SIZE_Y,
               (*m_imageList)["BackGround"]->GetMemDC(), 0, 0, SRCCOPY);

        GAME_MANAGER->Update();
        DRAW_MANAGER->Update();

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