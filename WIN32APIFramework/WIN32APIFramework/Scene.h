#pragma once
#include "CollisionManager.h"
#include "ObjectManager.h"

class Scene
{
public:
	virtual void Update() = 0;

    Scene();
    virtual ~Scene();
};

