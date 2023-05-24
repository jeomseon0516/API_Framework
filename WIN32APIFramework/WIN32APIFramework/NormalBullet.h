#pragma once
#include "BulletBridge.h"
#include "ObjectPoolManager.h"
#include "Object.h"

#define LIFE_TIME 10.0f

class NormalBullet : public BulletBridge
{
private:

    float _lifeTime;
    float _speed;

    void Start() override;
    void Update() override
    {
        _lifeTime += 0.1f;
        Move();

        if (_lifeTime >= LIFE_TIME)
            Destroy();
    }

    void Move() { gameObject->transform.position += gameObject->GetDirection() * _speed; }

public:

    void Destroy() override;

    void Render() override { gameObject->transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }

    NormalBullet();
    ~NormalBullet();
};

