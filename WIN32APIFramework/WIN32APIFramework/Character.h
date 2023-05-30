#pragma once

#include "Bullet.h"
#include "InputManager.h"
#include "CharacterBridge.h"
#include "Acrobatics.h"
#include "Prototype.h"
#include "Attack.h"
#include "Idle.h"
#include "Jump.h"

class Character : public LivingObject
{
private:
    friend class Idle;
    friend class Jump;
    friend class Attack;
    friend class Acrobatics;

    State* _state;
    void Start() override;
public:

    void Update() override
    {
        if (_time + _frame.frameTime < GetTickCount64())
        {
            _time = GetTickCount64();
            ++_frame.countX;
        }

        _bridge->Update();
        _state->Action(this);
    }

    void Render() override
    {
        transform.ImageRender(DRAW_MANAGER->GetMemDC(),
            (*m_imageList)[_layerName]->GetMemDC(),
            _frame.countX % _frame.locomotion.endFrameX,
            _frame.locomotion.countY);
    }

    void FireBullet(BulletBridge* bulletBridge);

    Character* Clone()const override { return new Character(*this); }
public:
    Character(const Transform& _transform);
    Character();
    ~Character() override;
};