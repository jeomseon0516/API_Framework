#include "Object.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
    MakeCollisionData("Enemy", "NormalBullet");
}
ObjectManager::~ObjectManager() {}

// 오브젝트의 라이프 사이클 관리
inline void ObjectManager::Update()
{
    UpdateFromCustomFunction(&ObjectManager::ObjectUpdate);

    for (CollisionData* collisionData : _collisionData)
    {
        if (!collisionData->isActive) continue;

        list<Object*>* firstList = collisionData->firstList;
        list<Object*>* secondList = collisionData->secondList;

        for (Object* first : *firstList)
        {
            for (Object* second : *secondList)
            {
                if (first == second) continue; // 같은 레이어의 객체끼리 충돌 시켰을 때 가르키는 포인터가 같은 객체일 경우

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
    UpdateFromCustomFunction(&ObjectManager::ObjectRender);
}

inline bool ObjectManager::ObjectUpdate(list<Object*>* objectList, list<Object*>::iterator& iter)
{
    return true;
}

inline bool ObjectManager::ObjectRender(list<Object*>* objectList, list<Object*>::iterator& iter)
{
    Object* obj = *iter;

    obj->Render();


    return true;
}

inline void ObjectManager::UpdateFromCustomFunction(bool(ObjectManager::*const function)(list<Object*>*, list<Object*>::iterator&))
{
    for (const pair<const string, list<Object*>*>& item : _objectMap)
    {
        list<Object*>* objectList = item.second;
        list<Object*>::iterator iter = objectList->begin();

        while (iter != objectList->end())
        {
            if ((this->*function)(objectList, iter))
                ++iter;
        }
    }
}

void ObjectManager::MakeFromKeyCollisionList(const string& key)
{
    if (_objectMap.find(key) != _objectMap.end()) return;
    _objectMap.insert(make_pair(key, new list<Object*>()));
}

void ObjectManager::PushBackObject(const string& key, Object* object)
{
    MakeFromKeyCollisionList(key);
    _objectMap[key]->push_back(object);
}

void ObjectManager::MakeCollisionData(const string& firstKey, const string& secondKey)
{
    MakeFromKeyCollisionList(firstKey);
    MakeFromKeyCollisionList(secondKey);

    string key = firstKey + secondKey;

    for (CollisionData* collisionData : _collisionData)
        if (collisionData->key == key) return; // 해당 키 값이 이미 존재한다면?

    _collisionData.push_back(new CollisionData(_objectMap[firstKey], _objectMap[secondKey], key));
}

void ObjectManager::AllClear()
{
    for (const pair<const string, list<Object*>*>& item : _objectMap)
    {
        list<Object*>* objList = item.second;
    }
}