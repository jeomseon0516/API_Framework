#pragma once
#include "Bridge.h"
#include "ObjectPoolManager.h"
#include "Object.h"

#define LIFE_TIME 10.0F

class BulletBridge : public Bridge
{
protected:
    float _speed;
    float _lifeTime;
public:
    void Start() override;
    void Destroy() override;

    void Update() override
    {
        Move();
        CalcLifeTime();
    }

    void Render() override { gameObject->transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }

protected:
    virtual void Move() = 0;
private:

    void CalcLifeTime()
    {
        _lifeTime += 0.1f;

        if (_lifeTime >= LIFE_TIME)
            Destroy();
    }

public:
     BulletBridge();
    ~BulletBridge();
};