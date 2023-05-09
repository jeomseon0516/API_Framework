#include "CollisionManager.h"
#include "Object.h"

SINGLETON_INIT(CollisionManager)

CollisionManager::CollisionManager()
{
    MakePairCollisionList("Enemy", "CharacterBullet");
}

CollisionManager::~CollisionManager() {}

void CollisionManager::Update()
{
    for (int i = 0; i < _physicsList.size(); ++i)
    {
        if (!_physicsList[i].isActive) continue;

        vector<Object*>* firstList = _physicsList[i].firstList;
        vector<Object*>* secondList = _physicsList[i].secondList;

        for (int j = 0; j < firstList->size(); ++j)
        {
            for (int k = 0; k < secondList->size(); ++k)
            {
                if (firstList->at(j) == secondList->at(k)) continue; // 같은 레이어의 객체끼리 충돌 시켰을 때 가르키는 포인터가 같은 객체일 경우

                float distance = GET_DISTANCE(firstList->at(j)->transform.position, secondList->at(k)->transform.position);
                float collisionDistance = firstList->at(j)->transform.GetSize().x * 0.5f + secondList->at(k)->transform.GetSize().x * 0.5f;

                if (distance <= collisionDistance)
                {
                    firstList->at(j)->OnCollision(secondList->at(k));
                    secondList->at(k)->OnCollision(firstList->at(j));

                    ELEMENT_ERASE_TO_CONDITION(Object, secondList->at(k)->GetIsDie(), k, (*secondList));
                }
            }
            ELEMENT_ERASE_TO_CONDITION(Object, firstList->at(j)->GetIsDie(), j, (*firstList));
        }
    }
}

// .. 충돌 처리할 레이어의 객체들을 저장합니다.
void CollisionManager::PushPhysicsMap(string key, Object* object)
{
    MakeFromKeyCollisionList(key);
    _physicsMap[key]->push_back(object);
}

// .. 충돌 처리시킬 레이어 두개를 페어로 만들어서 충돌 처리를 구현합니다. 
void CollisionManager::MakePairCollisionList(string firstKey, string secondKey)
{
    MakeFromKeyCollisionList(firstKey);
    MakeFromKeyCollisionList(secondKey);

    _physicsList.push_back(PhysicsCellData(_physicsMap[firstKey], _physicsMap[secondKey], firstKey + secondKey));
}

// .. 해당 키값이 존재 하지 않는다면?
void CollisionManager::MakeFromKeyCollisionList(string key)
{
    if (_physicsMap.find(key) != _physicsMap.end()) return;

    vector<Object*>* newObjectList = new vector<Object*>();
    _physicsMap.insert(make_pair(key, newObjectList));
}

void CollisionManager::AllClear()
{
    for (int i = 0; i < _physicsList.size(); ++i)
    {
        CLEAR_VECTOR(Object, (*_physicsList[i].firstList));
        CLEAR_VECTOR(Object, (*_physicsList[i].secondList));
    }
}