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
    list<Object*>* GetObjectList(const string& key) { return &poolList[key]; }
    void ReturnObject(const string& key, Object* obj);
public:
    ~ObjectPoolManager();
};

