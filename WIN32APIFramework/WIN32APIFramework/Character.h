#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Bullet.h"
#include "InputManager.h"

#define SPEED 10.0F
#define COOLTIME 0.2F

class Character : public Object
{
private:
	Vector2 _beforePosition;
	Vector2 _direction;
	Vector2 _lookAt;

	float _coolTime;
	int _keyCode;

	void Update() override;
	void Start()  override;

	void FireBullet();
	bool CheckKeyDown(int keyCode);

public:
	~Character() override {}
};
#endif

