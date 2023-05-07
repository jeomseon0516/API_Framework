#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

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

	Vector2 _movePoint;
	Object* _target = nullptr;
	STATE _state;

	void Idle();
	void Move(); 

	void Start() override;
	void Update() override;

public:

	void OnCollision(Object* obj) override { _isDie = true; }

	void Render() override { transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }
	void SetTarget(Object* obj) { _target = obj; }

	~Enemy() override {}
};
#endif
