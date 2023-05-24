#include "ObjectPoolManager.h"
#include "Prototype.h"
#include "Object.h"

ObjectPoolManager::ObjectPoolManager()  {}
ObjectPoolManager::~ObjectPoolManager() {}

Object* ObjectPoolManager::GetGameObject(const string& key)
{
    map<string, list<Object*>>::iterator iter = poolList.find(key);

    if (iter == poolList.end())
        return GET_SINGLETON(Prototype)->GetGameObject(key)->Clone()->ObjStart();

    list<Object*>* objectList = &iter->second;

    if (objectList->size() == 0)
        return GET_SINGLETON(Prototype)->GetGameObject(key)->Clone()->ObjStart();

    Object* obj = objectList->front()->ObjStart();
    objectList->pop_front();

    return obj;
}

void ObjectPoolManager::ReturnObject(const string& key, Object* obj)
{
    if (poolList.find(key) == poolList.end())
        poolList.insert(make_pair(key, list<Object*>()));

    poolList[key].push_back(obj);
}