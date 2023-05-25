#include "Bullet.h"

Bullet::Bullet(const Transform& _transform) : LivingObject(_transform) {}
Bullet::Bullet() {}
Bullet::~Bullet() {}

void Bullet::Start()
{
    transform.SetSize(Vector2(20, 20));
    _layerName = "NormalBullet";
}

void Bullet::Destroy()
{
    _destroyState = DESTROY_STATE::POOL;
    GET_SINGLETON(ObjectPoolManager)->ReturnObject(_layerName, this);
}