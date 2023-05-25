#include "Enemy.h"

Enemy::Enemy(const Transform& _transform) : LivingObject(_transform) {}
Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::Start()
{
    SetBridge(new EnemyBridge());
    _layerName = "Enemy";
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
