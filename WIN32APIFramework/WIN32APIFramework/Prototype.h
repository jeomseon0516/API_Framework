#pragma once
#include "Include.h"
#include "Transform.h"
#include "Singleton.h"

class Object;

class Prototype
{
    SINGLETON(Prototype);
private:
    map<string, Object*> _prototypeObject;
public:
    void Start();

    Object* GetGameObject(const string& key)
    {
        map<string, Object*>::iterator iter = _prototypeObject.find(key);

        if (iter == _prototypeObject.end())
            return nullptr;

        return iter->second;
    }

public:
    ~Prototype();
};