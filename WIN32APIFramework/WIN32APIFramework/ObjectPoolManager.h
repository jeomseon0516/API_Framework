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
    list<Object*>* GetGameObjectList(const string& key);
    Object* GetGameObject(const string& key);
    void ReturnObject(const string& key, Object* obj);
public:
    ~ObjectPoolManager();
};

