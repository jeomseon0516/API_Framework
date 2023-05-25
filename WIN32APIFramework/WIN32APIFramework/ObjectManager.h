#pragma once

#include "Include.h"
#include "Singleton.h"

using namespace std;

#define OBJECT_MANAGER (*ObjectManager::GetInstance())

class Object;

struct CollisionData
{
    bool isActive;
    string key;
    list<Object*>* firstList;
    list<Object*>* secondList;

    CollisionData(list<Object*>* _firstList, list<Object*>* _secondList, string _key, bool _isActive = true) :
        firstList(_firstList), secondList(_secondList), key(_key), isActive(_isActive) {}
};

class ObjectManager : public Singleton
{
    SINGLETON(ObjectManager);
private:
    list<CollisionData*> _collisionData;
    map<string, list<Object*>*> _objectMap;

    inline void Update() override;
public:

    inline bool ObjectUpdate(list<Object*>* obejctList, list<Object*>::iterator& iter);
    inline bool ObjectRender(list<Object*>* obejctList, list<Object*>::iterator& iter);
    inline void UpdateFromCustomFunction(bool(ObjectManager::*const function)(list<Object*>*, list<Object*>::iterator&));
    void MakeFromKeyCollisionList(const string& key);
    void PushBackObject(const string& key, Object* object);
    void MakeCollisionData(const string& firstKey, const string& secondKey);
    void AllClear();

    ~ObjectManager() override;
};