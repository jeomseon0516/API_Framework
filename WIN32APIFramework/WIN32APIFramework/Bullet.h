#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"

#define LIFETIME 10.0f

class Bullet : public Object
{
private:

	Vector2 _direction;

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
	void SetDirection(Vector2 direction) { _direction = direction; }

    Bullet();
    ~Bullet() override;
};
#endif

