#pragma once
#include "Scene.h"
#include "Logo.h"
#include "InputManager.h"

class Menu : public Scene
{
public:
    void Update() override
    {
        if (INPUT_MANAGER->GetKey() & SPACE)
            SCENE_MANAGER->SetScene(new Logo());
    }

    Menu();
    ~Menu();
};

