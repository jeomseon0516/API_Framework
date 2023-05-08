#include "Enemy.h"

void Enemy::Start()
{
	transform = Transform(Vector2(500, 200), Vector2(30, 30));
	_coolTime = 0;
	_speed = 3.0f;
	_state = MOVE;
	_movePoint = Vector2(300, 400);
    _layerName = "Enemy";
	COLLISION_MANAGER->PushPhysicsMap(_layerName, this);
}

void Enemy::Update()
{
	switch (_state)
	{
	case IDLE:
		Idle();
		break;
	case MOVE:
		Move();
		break;
	}
}

void Enemy::Idle()
{
	// ?
}

void Enemy::Move()
{
    if (_target == nullptr) return;
	transform.position += GET_FROM_POSITION_TO_DIRECTION(_target->transform.position, transform.position) * _speed;
}