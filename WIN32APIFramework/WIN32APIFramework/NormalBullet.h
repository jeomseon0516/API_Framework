#pragma once
#include "BulletBridge.h"
#include "ObjectPoolManager.h"
#include "Object.h"

#define LIFETIME 10.0f

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

        if (_lifeTime >= LIFETIME)
            Destroy();
    }

    void Move() { gameObject->transform.position += gameObject->GetDirection() * _speed; }

public:

    void Destroy() override;
    void Render() override { gameObject->transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }
    void SetDirection(const Vector2& direction) { gameObject->SetDirection(direction); }

    NormalBullet();
    ~NormalBullet() override;
};

