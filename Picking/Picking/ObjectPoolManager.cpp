#include "ObjectPoolManager.h"
#include "Prototype.h"
#include "Object.h"

ObjectPoolManager::ObjectPoolManager()  {}
ObjectPoolManager::~ObjectPoolManager() {}

list<Object*>* ObjectPoolManager::GetGameObjectList(const string& key)
{
    map<string, list<Object*>>::iterator iter = poolList.find(key);
    return iter == poolList.end() ? nullptr : &iter->second;
}

Object* ObjectPoolManager::GetGameObject(const string& key)
{
    list<Object*>* objectList = GetGameObjectList(key);

    if (!objectList || objectList->size() == 0)
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