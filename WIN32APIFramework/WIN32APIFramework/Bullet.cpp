#include "Bullet.h"

void Bullet::Start()
{
	_transform.SetSize(Vector2(20, 20));
	_lifeTime = 0;
	_speed = 20.0f;
}

void Bullet::Update()
{
	_lifeTime += 0.01f;
	Move();

	if (_lifeTime >= LIFETIME)
		_isDie = true;
}

void Bullet::Move()
{
	_transform.SetPosition(_transform.GetPosition() + _direction * _speed);
}