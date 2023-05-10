#include "Object.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager() {}
ObjectManager::~ObjectManager() {}

Object* ObjectManager::GetFromIndexToObject(int& index)
{
    if (CATCH_RELASE_ELEMENT(Object, _objectList[index]->GetIsDie(), index, &_objectList, &_destroyList)) return nullptr;
    return _objectList[index];
}

// 오브젝트의 라이프 사이클 관리
void ObjectManager::Update()
{
    for (int i = 0; i < _objectList.size(); ++i)
    {
        if (CATCH_RELASE_ELEMENT(Object, _objectList[i]->GetIsDie(), i, &_objectList, &_destroyList)) continue;
        _objectList[i]->ObjUpdate();
    }

    COLLISION_MANAGER->Update();
    CLEAR_VECTOR(Object, _destroyList);

    // 렌더는 가장 마지막
    for (int i = 0; i < _objectList.size(); ++i)
        _objectList[i]->Render();
}

void ObjectManager::PushBackObject(Object* object)
{
    _objectList.push_back(object);
}

void ObjectManager::AllClear()
{
    CLEAR_VECTOR(Object, _destroyList);
    CLEAR_VECTOR(Object, _objectList);
}
