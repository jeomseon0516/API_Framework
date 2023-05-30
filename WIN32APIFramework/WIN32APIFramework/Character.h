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
    friend class Acrobatics;
    friend class Attack;
    friend class Jump;
    friend class Idle;

    State<Character>* _state;
    bool _isFlipX;

    void Start() override;
public:

    void Update() override
    {
        _state->Action(this);
        _bridge->Update();
    }

    void Render() override
    {
        if      (_direction.x > 0) 
            _isFlipX = false;
        else if (_direction.x < 0) 
            _isFlipX = true;

        transform.ImageRender(DRAW_MANAGER->GetMemDC(),
            (*m_imageList)[_layerName]->GetMemDC(),
            _frame.countX % _frame.locomotion.endFrameX,
            _frame.locomotion.countY + (_isFlipX ? 9 : 0));
    }

    void FireBullet(BulletBridge* bulletBridge);
    Character* Clone()const override { return new Character(*this); }

public:
    Character(const Transform& _transform);
    Character();
    ~Character() override;
};