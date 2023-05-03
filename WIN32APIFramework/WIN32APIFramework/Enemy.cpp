#include "Enemy.h"

void Enemy::Start()
{
	transform = Transform(Vector2(500, 200), Vector2(300, 300));
	_coolTime = 0.0f;
	_speed = 3.0f;
	_state = MOVE;
	_movePoint = Vector2(300, 400);
	COLLISIONMANAGER->PushEnemyList(this);
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

void Enemy::Render()
{
	transform.DrawEllipse(DRAWMANAGER->GetHdc());
}

void Enemy::Idle()
{
	
	// ?
}

void Enemy::Move()
{
	float distance = Mathf::GetDistance(_target->transform.position, transform.position);

	Vector2 direction = Mathf::GetFromPositionToDirection(_target->transform.position, transform.position);
	transform.position = transform.position + direction * _speed;
}