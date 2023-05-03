#include "Bullet.h"

void Bullet::Start()
{
	transform.SetSize(Vector2(20, 20));
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
	transform.position = transform.position + _direction * _speed;
}