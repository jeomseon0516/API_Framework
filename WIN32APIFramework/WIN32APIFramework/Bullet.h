#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"
#include "ObjectPoolManager.h"
#include "NormalBullet.h"

class Bullet : public Object
{
private:
    void Start() override;
public:

    void Update() override
    {
        _bridge->Update();
    }

    void Destroy() override;
    void Render() override { transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }

    Bullet* Clone()const { return new Bullet(*this); }

    Bullet(const Transform& _transform);
    Bullet();
    ~Bullet();
};
#endif

