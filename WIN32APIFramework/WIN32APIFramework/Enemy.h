#pragma once
#include "Object.h"

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
	void SetTarget(Object* obj) { _target = obj; }

	~Enemy()override {}
};

