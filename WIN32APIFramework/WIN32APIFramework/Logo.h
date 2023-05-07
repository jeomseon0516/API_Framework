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

     Logo() { (new Object)->transform = Transform(Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f, Vector2(100, 200)); }
    ~Logo() {}
};

