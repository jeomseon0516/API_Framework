#pragma once
#include "Object.h"
#include "CollisionManager.h"

enum STATE
{
	IDLE = 0,
	MOVE
};

class Enemy : public Object
{
private:

	int _coolTime;
	float _speed;

	Object* _target;
	Vector2 _movePoint;
	STATE _state;

	void Idle();
	void Move(); 

	void Start() override;
	void Update() override;

public:

	void OnCollision(Object* obj) { _isDie = true; }

	void Render() override;
	void SetTarget(Object* obj) { _target = obj; }

	~Enemy() override {}
};

