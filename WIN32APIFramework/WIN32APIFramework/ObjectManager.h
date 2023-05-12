#pragma once
#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "Include.h"
#include "Singleton.h"

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
    vector<Object*>* firstList;
    vector<Object*>* secondList;

    CollisionData(vector<Object*>* _firstList, vector<Object*>* _secondList, string _key, bool _isActive = true) : 
        firstList(_firstList), secondList(_secondList), key(_key), isActive(_isActive) {}
};

class ObjectManager : public Singleton
{
    SINGLETON(ObjectManager);
private:

    vector<CollisionData> _collisionData;
    vector<Object*> _initList; // 이니셜 라이저 전용

    vector<vector<Object*>*> _objectLists; // 맵에 담긴 오브젝트를 똑같이 가지고 있는다. iterator 순환은 너무 느리기 때문
    map<string, vector<Object*>*> _objectMap;

    void Update() override;

public:

    void MakeFromKeyCollisionList(string key);
    void PushBackObject(string key, Object* object);
    void MakeCollisionData(string firstKey, string secondKey);
    void InitObject(Object* object);
    void AllClear();

    ~ObjectManager() override;
};
#endif