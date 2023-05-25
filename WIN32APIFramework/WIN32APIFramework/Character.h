#pragma once

#include "Bullet.h"
#include "InputManager.h"
#include "Prototype.h"

#define SPEED 10.0F
#define COOL_TIME 0.4F

class Character : public Object
{
private:
	Vector2 _beforePosition;
	Vector2 _lookAt;

	float _coolTime;
	int _keyCode;

	void Start() override;

public:

    void Update() override
    {
        _coolTime += 0.1f;

        _beforePosition = transform.position;
        _direction = Vector2(INPUT_MANAGER->GetAxisHorizontal(), INPUT_MANAGER->GetAxisVertical());

        if (abs(_direction.x) > 0 && abs(_direction.y) > 0)
            _lookAt = _direction;

        transform.position += _direction * SPEED;
    }

	void FireBullet(BulletBridge* bulletBridge);

    Character* Clone()const override { return new Character(*this); }

    Character(const Transform& _transform);
    Character();
    ~Character() override;
};