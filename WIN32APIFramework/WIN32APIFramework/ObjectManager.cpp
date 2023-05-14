#include "Object.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager() 
{
    MakeCollisionData("Enemy", "CharacterBullet");
}
ObjectManager::~ObjectManager() {}

//
// 오브젝트의 라이프 사이클 관리
void ObjectManager::Update()
{
    for (int i = 0; i < _initList.size(); ++i)
    {
        _initList[i]->ObjUpdate();
        ELEMENT_ERASE_TO_CONDITION(Object, true, i, _initList);
    }

    for (int i = 0; i < _objectLists.size(); ++i)
    {
        vector<Object*>* objectList = _objectLists[i];

        for (int j = 0; j < objectList->size(); ++j)
            objectList->at(j)->ObjUpdate();
    }

    for (int i = 0; i < _collisionData.size(); ++i)
    {
        if (!_collisionData[i].isActive) continue;

        vector<Object*>* firstList  = _collisionData[i].firstList;
        vector<Object*>* secondList = _collisionData[i].secondList;

        for (int j = 0; j < firstList->size(); ++j)
        {
            Object* first = firstList->at(j);

            for (int k = 0; k < secondList->size(); ++k)
            {
                Object* second = secondList->at(k);

                if (first == second)
                    continue; // 같은 레이어의 객체끼리 충돌 시켰을 때 가르키는 포인터가 같은 객체일 경우

                float distance = GET_DISTANCE(first->transform.position, second->transform.position);
                float collisionDistance = first->transform.GetSize().x * 0.5f + second->transform.GetSize().x * 0.5f;

                if (distance <= collisionDistance)
                {
                    first->OnCollision(second);
                    second->OnCollision(first);
                }
            }
        }
    }

    // 렌더는 가장 마지막
    for (int i = 0; i < _objectLists.size(); ++i)
    {
        vector<Object*>* objectList = _objectLists[i];

        for (int j = 0; j < objectList->size(); ++j)
        {
            Object* obj = objectList->at(j);
            obj->Render();

            ELEMENT_ERASE_TO_CONDITION(Object, obj->GetIsDie(), j, (*objectList));
        }
    }
}

void ObjectManager::MakeFromKeyCollisionList(string key)
{
    if (_objectMap.find(key) != _objectMap.end()) return;

    vector<Object*>* newObjectList = new vector<Object*>();

    _objectMap.insert(make_pair(key, newObjectList));
    _objectLists.push_back(newObjectList);
}

void ObjectManager::PushBackObject(string key, Object* object)
{
    MakeFromKeyCollisionList(key);

    _objectMap[key]->push_back(object);
}

void ObjectManager::MakeCollisionData(string firstKey, string secondKey)
{
    MakeFromKeyCollisionList(firstKey);
    MakeFromKeyCollisionList(secondKey);

    string key = firstKey + secondKey;

    for (int i = 0; i < _collisionData.size(); ++i)
        if (_collisionData[i].key == key) return;

    CollisionData collisionData = CollisionData(_objectMap[firstKey], _objectMap[secondKey], key);
    _collisionData.push_back(collisionData);
}

void ObjectManager::InitObject(Object* object)
{
    _initList.push_back(object);
}

void ObjectManager::AllClear()
{
    for (int i = 0; i < _objectLists.size(); ++i)
        CLEAR_VECTOR(Object, (*_objectLists[i]));
}
