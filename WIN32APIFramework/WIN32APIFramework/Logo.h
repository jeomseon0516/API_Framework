#pragma once
#include "Scene.h"
#include "Main.h"
#include "SceneManager.h"
#include "InputManager.h"

class Logo : public Scene
{
public:
    void Update() override
    {
        if (INPUT_MANAGER->GetKey() & RETURN)
            SCENE_MANAGER->SetScene(new Main());
    }

    Logo();
    ~Logo();
};