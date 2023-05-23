#include "ObjectPoolManager.h"
#include "Object.h"

ObjectPoolManager::ObjectPoolManager()  {}
ObjectPoolManager::~ObjectPoolManager() {}

void ObjectPoolManager::ReturnObject(Object* obj)
{
    poolList.push_back(obj);
}