#include "Object.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
    MakeCollisionData("Enemy", "CharacterBullet");
}
ObjectManager::~ObjectManager() {}

// 오브젝트의 라이프 사이클 관리
void ObjectManager::Update()
{
    for (int i = 0; i < _initList.size(); ++i)
    {
        _initList[i]->ObjUpdate();
        ELEMENT_ERASE_TO_CONDITION(Object, true, i, _initList);
    }

    UpdateFromCustomFunction(&ObjectManager::ObjectUpdate);

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
    UpdateFromCustomFunction(&ObjectManager::ObjectRender);
}

void ObjectManager::ObjectUpdate(vector<Object*>* objList, int& index)
{
    objList->at(index)->ObjUpdate();
}

void ObjectManager::ObjectRender(vector<Object*>* objList, int& index)
{
    Object* obj = objList->at(index);
    obj->Render();
    ELEMENT_ERASE_TO_CONDITION(Object, obj->GetIsDie(), index, (*objList));
}

void ObjectManager::UpdateFromCustomFunction(void(ObjectManager::*const function)(vector<Object*>*, int&))
{
    for (map<string, vector<Object*>*>::iterator iter = _objectMap.begin(); iter != _objectMap.end(); ++iter)
    {
        vector<Object*>* objectList = iter->second;

        for (int j = 0; j < objectList->size(); ++j)
            (this->*function)(objectList, j);
    }
}

void ObjectManager::MakeFromKeyCollisionList(const string& key)
{
    if (_objectMap.find(key) != _objectMap.end()) return;
    _objectMap.insert(make_pair(key, new vector<Object*>()));
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

    for (int i = 0; i < _collisionData.size(); ++i)
        if (_collisionData[i].key == key) return;

    _collisionData.push_back(CollisionData(_objectMap[firstKey], _objectMap[secondKey], key));
}

void ObjectManager::InitList(Object* obj)
{
    _initList.push_back(obj);
}

void ObjectManager::AllClear()
{
    for (map<string, vector<Object*>*>::iterator iter = _objectMap.begin(); iter != _objectMap.end(); ++iter)
        CLEAR_VECTOR(Object, (*iter->second));
}