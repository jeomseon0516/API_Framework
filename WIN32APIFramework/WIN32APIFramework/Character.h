#pragma once

#include "Bullet.h"
#include "InputManager.h"
#include "CharacterBridge.h"
#include "Prototype.h"

class Character : public LivingObject
{
private:
	void Start() override;
public:

    void Update() override
    {
        _bridge->Update();
    }

	void FireBullet(BulletBridge* bulletBridge);

    Character* Clone()const override { return new Character(*this); }
public:
    Character(const Transform& _transform);
    Character();
    ~Character() override;
};