#pragma once
#ifndef __COLLISION_MANAGER_H__
#define __COLLISION_MANAGER_H__

#include "Include.h"
#include "Singleton.h"

#define COLLISION_MANAGER CollisionManager::GetInstance()

class Object;

struct PhysicsCellData
{
    bool isActive;
    string key;
    vector<Object*>* firstList;
    vector<Object*>* secondList;

    PhysicsCellData(vector<Object*>* firstList, vector<Object*>* secondList, string key, bool isActive = true)
    {
        this->key = key;
        this->isActive   = isActive;
        this->firstList  = firstList;
        this->secondList = secondList;
    }
};

class CollisionManager
{
    SINGLETON(CollisionManager);
    // 벡터는 포인터를 사용합니다. 
    // 같은 벡터를 PhysicsList와 PhysicsMap 두 곳에서 사용하기 때문에 포인터를 이용해서 요소의 추가/제거에 효율적으로 코드를 작성할 수 있습니다.
    // 충돌을 하는 오브젝트들은 레이어 별로 확인을 합니다. MakePair가 된 레이어들끼리만 충돌 검사를 합니다.
    vector<PhysicsCellData> _physicsList;
    // 콜리전 매니저는 Layer별로 오브젝트 리스트에 담아 관리합니다.
    map<string, vector<Object*>*> _physicsMap;

public:
    void Update();

    void PushPhysicsMap(string, Object* object);
    void MakePairCollisionList(string firstKey, string secondKey);
    // .. 해당 함수는 키값으로 초기화만 해주는 값입니다.
    void MakeFromKeyCollisionList(string key);

    void AllClear();

    ~CollisionManager();
};

#endif
