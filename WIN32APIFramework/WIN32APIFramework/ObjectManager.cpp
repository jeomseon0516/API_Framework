#include "Object.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
    MakeCollisionData("Enemy", "CharacterBullet");
}
ObjectManager::~ObjectManager() {}

// 오브젝트의 라이프 사이클 관리
inline void ObjectManager::Update()
{
    for (list<Object*>::iterator iter = _initList.begin();;)
    {
        if (iter == _initList.end())
            break;

        (*iter)->ObjUpdate();
        ELEMENT_ERASE_TO_CONDITION(Object, true, _initList, iter);

        ++iter;
    }

    UpdateFromCustomFunction(&ObjectManager::ObjectUpdate);

    for (list<CollisionData*>::iterator iter = _collisionData.begin(); iter != _collisionData.end(); ++iter)
    {
        CollisionData* collisionData = *iter;

        if (!collisionData->isActive) 
            continue;

        list<Object*>* firstList = collisionData->firstList;
        list<Object*>* secondList = collisionData->secondList;

        for (list<Object*>::iterator firstIter = collisionData->firstList->begin(); firstIter != firstList->end(); ++firstIter)
        {
            Object* first = *firstIter;

            for (list<Object*>::iterator secondIter = collisionData->secondList->begin(); secondIter != secondList->end(); ++secondIter)
            {
                Object* second = *secondIter;

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
    UpdateFromCustomFunction(&ObjectManager::ObjectRender);
}

inline void ObjectManager::ObjectUpdate(list<Object*>* anyList, list<Object*>::iterator iter)
{
    (*iter)->ObjUpdate();
}

inline void ObjectManager::ObjectRender(list<Object*>* anyList, list<Object*>::iterator iter)
{
    Object* obj = *iter;

    obj->Render();
    ELEMENT_ERASE_TO_CONDITION(Object, obj->GetIsDie(), (*anyList), iter);
}

inline void ObjectManager::UpdateFromCustomFunction(void(ObjectManager::* const function)(list<Object*>*, list<Object*>::iterator))
{
    for (pair<const string, list<Object*>*> item : _objectMap)
    {
        list<Object*>* objectList = item.second;

        for (list<Object*>::iterator iter = objectList->begin();;)
        {
            (this->*function)(objectList, iter);

            if (iter == objectList->end())
                break;

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

    for (list<CollisionData*>::iterator iter = _collisionData.begin(); iter != _collisionData.end(); ++iter)
        if ((*iter)->key == key) return;

    _collisionData.push_back(new CollisionData(_objectMap[firstKey], _objectMap[secondKey], key));
}

void ObjectManager::InitList(Object* obj)
{
    _initList.push_back(obj);
}

void ObjectManager::AllClear()
{
    for (map<string, list<Object*>*>::iterator iter = _objectMap.begin(); iter != _objectMap.end(); ++iter)
    {
        list<Object*>* objList = iter->second;
        CLEAR_LIST(Object*, (*objList));
    }
}