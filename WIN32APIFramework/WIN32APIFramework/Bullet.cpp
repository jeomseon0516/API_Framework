#include "Bullet.h"

void Bullet::Start()
{
	transform.SetSize(Vector2(20, 20));
	_lifeTime = 0;
	_speed = 20.0f;
	_name = "Bullet";
    _layerName = "CharacterBullet";
    COLLISION_MANAGER->PushPhysicsMap(_layerName, this);
}

void Bullet::Update()
{
	_lifeTime += 0.1f;
	Move();

	if (_lifeTime >= LIFETIME)
		_isDie = true;
}

void Bullet::Render()
{
	transform.DrawEllipse(DRAW_MANAGER->GetHdc());
}

void Bullet::Move()
{
	transform.position += _direction * _speed;
}