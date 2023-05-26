#include "Enemy.h"

Enemy::Enemy(const Transform& _transform) : LivingObject(_transform) 
{
    _layerName = "Enemy";
}

Enemy::Enemy() 
{
    _layerName = "Enemy";
}

Enemy::~Enemy() {}

void Enemy::Start()
{
    SetBridge(new EnemyBridge());
}

void Enemy::OnCollision(Object* obj) 
{ 
    Destroy(); 
}

void Enemy::Destroy()
{
    _destroyState = DESTROY_STATE::POOL;
    GET_SINGLETON(ObjectPoolManager)->ReturnObject(_layerName, this);
}
