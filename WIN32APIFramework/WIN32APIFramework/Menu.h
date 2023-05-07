#pragma once
#include "Scene.h"
#include "Logo.h"

class Menu : public Scene
{
public:
    void Update() override
    {
        if (GetAsyncKeyState(VK_SPACE))
            SCENE_MANAGER->SetScene(new Logo());
    }

    Menu() 
    { 
        Object* obj = new Object();
        obj->transform = Transform(Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f, Vector2(500, 300));
    }
    ~Menu() {}
};

