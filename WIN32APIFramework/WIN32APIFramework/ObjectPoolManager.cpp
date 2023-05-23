#include "ObjectPoolManager.h"
#include "Object.h"

ObjectPoolManager::ObjectPoolManager()  {}
ObjectPoolManager::~ObjectPoolManager() {}

void ObjectPoolManager::ReturnObject(const string& key, Object* obj)
{
    if (poolList.find(key) == poolList.end())
        poolList.insert(make_pair(key, list<Object*>()));

    poolList[key].push_back(obj);
}