#include "BulletBridge.h"

BulletBridge::BulletBridge() {}
BulletBridge::~BulletBridge() {}

void BulletBridge::Start()
{
    gameObject->transform.SetSize(Vector2(20, 20));
    _lifeTime = 0;
}