#pragma once
#include "Singleton.h"
#include "Object.h"

#define COLLISIONMANAGER CollisionManager::GetInstance()

class CollisionManager : public Singleton<CollisionManager> 
{
private:
	friend class Singleton<CollisionManager>;

	vector<Object*> _enemyList;
	vector<Object*> _bulletList;

public:

	void Update() override;

	void PushEnemyList(Object* enemy) { _enemyList.push_back(enemy); }
	void PushBulletList(Object* bullet) { _bulletList.push_back(bullet); }

private:
	CollisionManager() {}
};

