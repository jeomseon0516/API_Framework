#pragma once
#ifndef __COLLISION_MANAGER_H__
#define __COLLISION_MANAGER_H__

#include "Include.h"
#include "Object.h"
#include "Singleton.h"

#define COLLISIONMANAGER CollisionManager::GetInstance()

class CollisionManager : public Singleton
{
	SINGLETON(CollisionManager)

	vector<Object*> _enemyList;
	vector<Object*> _bulletList;

public:

	void PushEnemyList(Object* enemy) { _enemyList.push_back(enemy); }
	void PushBulletList(Object* bullet) { _bulletList.push_back(bullet); }
};

#endif
