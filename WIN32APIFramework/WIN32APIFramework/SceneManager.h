#pragma once
#include "Include.h"
#include "Scene.h"

#define SCENE_MANAGER SceneManager::GetInstance()

class SceneManager : public Singleton
{
    SINGLETON(SceneManager);
    Scene* _scene = nullptr;

public:

    void Update() override { _scene->Update(); }
    void SetScene(Scene* scene);

    ~SceneManager();
};

