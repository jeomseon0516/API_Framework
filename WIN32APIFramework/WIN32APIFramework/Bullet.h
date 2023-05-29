#pragma once

#include "Object.h"
#include "ObjectPoolManager.h"
#include "NormalBullet.h"

class Bullet : public LivingObject
{
private:
    void Start() override;
    void SetBridge(Bridge* bridge) override {}
public:

    void Update() override
    {
        _bridge->Update();
    }

    void Destroy() override;
    void Render() override { transform.DrawEllipse(DRAW_MANAGER->GetMemDC()); }

    void SetBridge(BulletBridge* bridge) { Object::SetBridge(bridge); } // 형식을 제한 시키기 위한 코드

    Bullet* Clone()const { return new Bullet(*this); }

    Bullet(const Transform& _transform);
    Bullet();
    ~Bullet();
};