#pragma once
#include "Scene.h"
#include "Main.h"
#include "SceneManager.h"

class Logo : public Scene
{
public:
    void Update() override
    {
        if (GetAsyncKeyState(VK_RETURN))
            SCENE_MANAGER->SetScene(new Main());
    }

    Logo();
    ~Logo();
};

