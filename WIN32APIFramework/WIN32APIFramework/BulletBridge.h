#pragma once
#include "LivingObjectBridge.h"
#include "ObjectPoolManager.h"

#define LIFE_TIME 10.0F

class BulletBridge : public LivingObjectBridge
{
protected:
    float _lifeTime;
public:
    void Start() override;

    void Update() override
    {
        Move();
        CalcLifeTime();
    }

    void Render() override {}

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