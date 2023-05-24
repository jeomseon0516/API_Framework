#include "NormalBullet.h"

NormalBullet::NormalBullet()  {}
NormalBullet::~NormalBullet() {}

void NormalBullet::Start()
{
    gameObject->transform.SetSize(Vector2(20, 20));
    _lifeTime = 0;
    _speed = 20.0f;
}

void NormalBullet::Destroy()
{
}
