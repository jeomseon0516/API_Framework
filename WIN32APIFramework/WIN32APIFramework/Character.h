#pragma once
#include "Bullet.h"
#include "InputManager.h"

#define SPEED 10.0F
#define COOLTIME 10.0F

class Character : public Object
{
private:
	Vector2 _beforePosition;
	float _coolTime;
	int _keyCode;

	virtual void Update();
	virtual void Start();

	void FireBullet();
	bool CheckKeyDown(int keyCode);

public:
	Character() {}
	~Character() {}
};

