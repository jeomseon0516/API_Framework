#include "Bullet.h"

void Bullet::Start()
{
	Object::Start();

	_lifeTime = 0;
	_speed = 0.1f;
	_transform.SetSize(Vector2(10, 10));
}

void Bullet::ObjUpdate()
{
	_lifeTime += 0.1f;
	Move();

	if (_lifeTime >= LIFETIME)
		delete this;
}

void Bullet::Move()
{
	_transform.SetPosition(_transform.GetPosition() + _direction * _speed);
	_lifeTime = 0;
}