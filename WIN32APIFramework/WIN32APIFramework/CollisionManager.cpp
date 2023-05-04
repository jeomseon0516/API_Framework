#include "CollisionManager.h"

SINGLETON_INIT(CollisionManager)

CollisionManager::CollisionManager() {}

void CollisionManager::Update()
{
	for (int i = 0; i < _bulletList.size(); ++i)
	{
		for (int j = 0; j < _enemyList.size(); ++j)
		{
			float distance = Mathf::GetDistance(_bulletList[i]->transform.position, _enemyList[j]->transform.position);
			float collisionDistance = _bulletList[i]->transform.GetSize().x * 0.5f + _enemyList[j]->transform.GetSize().x * 0.5f;

			if (distance <= collisionDistance)
			{
				_bulletList[i]->OnCollision(_enemyList[j]);
				_enemyList[j]->OnCollision(_bulletList[i]);

				if (_enemyList[j]->GetIsDie())
				{
					_enemyList.erase(_enemyList.begin() + j);
					--j;
					continue;
				}
			}
		}
		if (_bulletList[i]->GetIsDie())
		{
			_bulletList.erase(_bulletList.begin() + i);
			--i;
			continue;
		}
	}
}
