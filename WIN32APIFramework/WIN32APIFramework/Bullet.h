#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"

#define LIFETIME 10.0f

class Bullet : public Object
{
private:

	float _lifeTime;
	float _speed;

	void Start() override;
    void Update() override
    {
        _lifeTime += 0.1f;
        Move();

        if (_lifeTime >= LIFETIME)
            _isDie = true;
    }

    void Move() { transform.position += _direction * _speed; }

public:

    void Render() override { transform.DrawEllipse(DRAW_MANAGER->GetHdc()); }
	void SetDirection(const Vector2& direction) { _direction = direction; }

    Bullet* Clone()const override { return new Bullet(*this); }
     
     Bullet(const Transform& _transform);
     Bullet();
    ~Bullet() override;
};
#endif

