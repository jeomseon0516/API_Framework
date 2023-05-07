#pragma once
#include "CollisionManager.h"
#include "ObjectManager.h"

class Scene
{
protected:
public:
	virtual void Update() = 0;

    Scene();
	virtual ~Scene() {}
};

