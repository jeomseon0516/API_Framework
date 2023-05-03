#pragma once
#include "Object.h"

#define LIFETIME 30.0f

class Bullet : public Object
{
private:

	Vector2 _direction;

	float _lifeTime;
	float _speed;

	void Move();

public:

	void Start() override;
	void Update() override;

	void SetDirection(Vector2 direction) { _direction = direction; }

	~Bullet()override {}
};

