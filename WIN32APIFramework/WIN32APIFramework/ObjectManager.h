#pragma once
#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "Include.h"
#include "Singleton.h"
#include "CollisionManager.h"

using namespace std;

class Object;
/*
    ..로직 순서 입니다. WinAPI 자체 while -> MainUpdate -> GameManager생성자 -> 각 매니저 들의 생성자 -> GameManager.Update() ->
                       최상위 클래스 Singleton의 Singleton Start 호출 -> Singleton을 상속받은 클래스의 Start호출.. -> ..GameManager->Update() 까지 다시 반복 후
                       -> 매니저 들의 Update() 호출 .. 반복
*/

#define OBJECT_MANAGER ObjectManager::GetInstance()

class ObjectManager : public Singleton
{
    SINGLETON(ObjectManager);
private:

    vector<Object*> _objectList;
    vector<Object*> _destroyList;

    void Update() override;

public:
    Object* GetFromIndexToObject(int& index);

    int ObjectListSize() { return (int)_objectList.size(); }

    void PushBackObject(Object* object);
    void AllClear();

    ~ObjectManager() override;
};
#endif