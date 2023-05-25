#include "Bullet.h"

Bullet::Bullet(const Transform& _transform) : Object(_transform) {}

Bullet::Bullet() {}
Bullet::~Bullet() {}

void Bullet::Start()
{
    transform.SetSize(Vector2(20, 20));
    _layerName = "NormalBullet";
}

void Bullet::Destroy()
{
    _isDie = POOL;
    GET_SINGLETON(ObjectPoolManager)->ReturnObject(_layerName, this);
}