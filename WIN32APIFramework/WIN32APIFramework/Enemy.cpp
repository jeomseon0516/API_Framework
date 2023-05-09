#include "Enemy.h"

void Enemy::OnCollision(Object* obj) { _isDie = true; }

Enemy::Enemy() {}
Enemy::~Enemy() {}

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
