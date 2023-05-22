#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Object.h"

enum STATE
{
    IDLE   = 0x00000001,
	MOVE   = 0x00000002,
    ATTACK = 0x00000004,
    HIT    = 0x00000008
};

class Enemy : public Object
{
private:

	int _coolTime;
	float _speed;

	Vector2 _movePoint;
	Object* _target = nullptr;
	STATE _state;

    void Idle() {}
    void Move()
    {
        if (_target == nullptr) return;
        transform.position += GET_FROM_POSITION_TO_DIRECTION(_target->transform.position, transform.position) * _speed;
    }

	void Start() override;
    void Update() override
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

public:

    void OnCollision(Object* obj) override;

	void Render() override { transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }
	void SetTarget(Object* obj) { _target = obj; }
     
    Enemy* Clone()const override { return new Enemy(*this); }

     Enemy(const Transform& _transform);
     Enemy();
    ~Enemy() override;
};
#endif
