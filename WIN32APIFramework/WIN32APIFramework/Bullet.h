#pragma once

#include "Object.h"
#include "ObjectPoolManager.h"
#include "NormalBullet.h"

class Bullet : public Object
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
    void Render() override { transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }

    void SetBridge(BulletBridge* bridge)
    {
        if (_bridge) delete _bridge;

        _bridge = bridge;
        _bridge->SetObject(this);
        _bridge->Start();
    }

    Bullet* Clone()const { return new Bullet(*this); }

    Bullet(const Transform& _transform);
    Bullet();
    ~Bullet();
};