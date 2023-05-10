#include "SceneManager.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() { delete _scene; }

void SceneManager::SetScene(Scene* scene)
{
    if (_scene != nullptr)
        delete _scene;

    _scene = scene;
}