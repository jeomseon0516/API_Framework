#pragma once
#include "Include.h"
#include "Scene.h"

#define SCENE_MANAGER (*SceneManager::GetInstance())

class SceneManager : public Singleton
{
    SINGLETON(SceneManager);
private:
    Scene* _scene = nullptr;

    void Update() override { _scene->Update(); }
public:

    void SetScene(Scene* scene);

    ~SceneManager() override;
};