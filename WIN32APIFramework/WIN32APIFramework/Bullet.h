#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"
#include "NormalBullet.h"

class Bullet : public Object
{
private:
	void Start() override;
    void Update() override
    {
        _bridge->Update();
    }

public:

    void Destroy() override;
    void Render() override { _bridge->Render(); }

    Bullet* Clone()const override { return new Bullet(*this); }
     
     Bullet(const Transform& _transform);
     Bullet();
    ~Bullet() override;
};
#endif

