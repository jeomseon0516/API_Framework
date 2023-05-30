#pragma once
#include "BulletBridge.h"

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

