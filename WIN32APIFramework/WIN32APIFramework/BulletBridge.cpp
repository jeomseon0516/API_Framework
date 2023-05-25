#include "BulletBridge.h"
#include "Object.h"

BulletBridge::BulletBridge() {}
BulletBridge::~BulletBridge() {}

void BulletBridge::Start()
{
    gameObject->transform.SetSize(Vector2(20, 20));
    _lifeTime = 0;
}

void BulletBridge::Destroy()
{
    gameObject->Destroy();
}