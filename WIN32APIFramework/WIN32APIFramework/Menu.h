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

    Menu();
    ~Menu();
};

