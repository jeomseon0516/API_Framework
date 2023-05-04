#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"
#include "CollisionManager.h"

#define LIFETIME 10.0f

class Bullet : public Object
{
private:

	Vector2 _direction;

	float _lifeTime;
	float _speed;

	void Start() override;
	void Update() override;

	void Move();

public:

	void Render() override;

	void SetDirection(Vector2 direction) { _direction = direction; }

	~Bullet() override {}
};
#endif

