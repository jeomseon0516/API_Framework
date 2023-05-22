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
        if (_prototypeObject.find(key) == _prototypeObject.end())
            return nullptr;

        return _prototypeObject[key];
    }

public:
    ~Prototype();
};