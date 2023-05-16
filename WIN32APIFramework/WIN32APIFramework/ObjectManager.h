#pragma once
#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "Include.h"
#include "Singleton.h"
//
using namespace std;

#define OBJECT_MANAGER (*ObjectManager::GetInstance())

class Object;

/*
    ..로직 순서 입니다. WinAPI 자체 while -> MainUpdate -> GameManager생성자 -> 각 매니저 들의 생성자 -> GameManager.Update() ->
                       최상위 클래스 Singleton의 Singleton Start 호출 -> Singleton을 상속받은 클래스의 Start호출.. -> ..GameManager->Update() 까지 다시 반복 후
                       -> 매니저 들의 Update() 호출 .. 반복
*/

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
    list<Object*> _initList; // 새로 생성된 오브젝트들은 해당 리스트에 push된 후 초기화후 erase된다.

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
    void InitList(Object* obj);
    void AllClear();

    ~ObjectManager() override;
};
#endif