#include "Bullet.h"

Bullet::Bullet() {}
Bullet::~Bullet() {}

void Bullet::Start()
{
    transform.SetSize(Vector2(20, 20));
    _lifeTime = 0;
    _speed = 20.0f;
    _name = "Bullet";
    _layerName = "CharacterBullet";
}

