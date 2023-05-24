#include "Bullet.h"

Bullet::Bullet(const Transform& _transform) : Object(_transform, new NormalBullet()) {}
Bullet::Bullet() {}
Bullet::~Bullet() {}

void Bullet::Start()
{
    _bridge->SetObject(this);
    _bridge->Start();
    _layerName = "CharacterBullet";
}

void Bullet::Destroy()
{
    _isDie = POOL;
    GET_SINGLETON(ObjectPoolManager)->ReturnObject(_layerName, this);
}
