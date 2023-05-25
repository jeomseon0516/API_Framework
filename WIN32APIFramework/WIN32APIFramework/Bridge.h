#pragma once
#include "Include.h"

class Object;

class Bridge
{
protected:
    Object* gameObject;
    Object* GetGameObject()const { return gameObject; }
public:
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Destroy() = 0;

    virtual void SetObject(Object* obj) { gameObject = obj; }

    Bridge();
    virtual ~Bridge();
};