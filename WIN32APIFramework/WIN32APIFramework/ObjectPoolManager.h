#pragma once
#include "Singleton.h"
#include "Include.h"

class Object;

class ObjectPoolManager
{
    SINGLETON(ObjectPoolManager);
private:
    list<Object*> poolList;

public:
    list<Object*>* GetObjectList() { return &poolList; }
    void ReturnObject(Object* obj);
public:
    ~ObjectPoolManager();
};

