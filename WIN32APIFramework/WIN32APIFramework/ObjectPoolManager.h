#pragma once
#include "Singleton.h"
#include "Include.h"

class Object;

class ObjectPoolManager
{
    SINGLETON(ObjectPoolManager);
private:
    map<string, list<Object*>> poolList;
public:
    Object* GetGameObject(const string& key);
    void ReturnObject(const string& key, Object* obj);
public:
    ~ObjectPoolManager();
};

