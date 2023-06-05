#pragma once
#include "ObjectManager.h"
#include "Prototype.h"

class Scene
{
public:
	virtual void Update() = 0;

    Scene();
    virtual ~Scene();
};