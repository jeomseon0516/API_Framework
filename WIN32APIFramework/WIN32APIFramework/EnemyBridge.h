#pragma once
#include "LivingObjectBridge.h"
#include "ObjectPoolManager.h"
#include "PlayerManager.h"

enum class STATE
{
    IDLE   = 0x00000001,
    MOVE   = 0x00000002,
    ATTACK = 0x00000004,
    HIT    = 0x00000008
};

class EnemyBridge : public LivingObjectBridge
{
private:
    int _coolTime;

    Vector2 _movePoint;
    Object* _target;
    STATE _state;

public:
    void Start() override;
    void Render() override {}

    void Update() override
    {
        switch (_state)
        {
        case STATE::IDLE:
            Idle();
            break;
        case STATE::MOVE:
            Move();
            break;
        }
    }

    void Idle() {}
    void Move()
    {
        if (!_target) return;
        gameObject->SetDirection(GET_FROM_POSITION_TO_DIRECTION(_target->transform.position, gameObject->transform.position));
    }

    void SetTarget(Object* target) { _target = target; }

public:
     EnemyBridge();
    ~EnemyBridge();
};

