#include "Enemy.h"

Enemy::Enemy(const Transform& _transform) : Object(_transform) {}
Enemy::Enemy()  {}
Enemy::~Enemy() {}

void Enemy::Start()
{
    transform = Transform(Vector2(500, 200), Vector2(30, 30));
    _target = PLAYER_MANAGER->GetCharacter();
    _coolTime = 0;
    _speed = 3.0f;
    _state = MOVE;
    _movePoint = Vector2(300, 400);
    _layerName = "Enemy";
}

void Enemy::OnCollision(Object* obj) 
{ 
    Destroy(); 
}

void Enemy::Destroy()
{
    _isDie = true;
    GET_SINGLETON(ObjectPoolManager)->ReturnObject(this);
}