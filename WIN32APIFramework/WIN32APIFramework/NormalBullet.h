#pragma once
#include "BulletBridge.h"

#define LIFE_TIME 10.0f

class NormalBullet : public BulletBridge
{
public:
    void Start() override;
private:
    void Move() override {}
public:
     NormalBullet();
    ~NormalBullet();
};

