#pragma once
#include "BulletBridge.h"

class GuideBullet : public BulletBridge
{
private:
    Object* _target;
public:
    // BulletBridge을(를) 통해 상속됨
    void Start() override;
private:
    void Move() override
    {
        float radian = GET_FROM_POSITION_TO_RADIAN(_target->transform.position, gameObject->transform.position);
        gameObject->SetDirection(Vector2(cosf(radian), sinf(radian)));
    }
public:
     GuideBullet();
    ~GuideBullet();
};

