#include "Bullet.h"

Bullet::Bullet(const Transform& _transform) : LivingObject(_transform) 
{
    _layerName = "NormalBullet";
}

Bullet::Bullet() 
{
    _layerName = "NormalBullet";
}

Bullet::~Bullet() {}

void Bullet::Start()
{
    transform.SetSize(Vector2(20, 20));
}

void Bullet::Destroy()
{
    _destroyState = DESTROY_STATE::POOL;
    GET_SINGLETON(ObjectPoolManager)->ReturnObject(_layerName, this);
}