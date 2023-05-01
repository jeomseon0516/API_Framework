#pragma once
#include "Bullet.h"

#define SPEED 0.1F
#define COOLTIME 3.0F

class Character : public Object
{
private:
	int _keyCode;
	Vector2 _beforePosition;
	float _coolTime;

protected:

	virtual void Start();
	virtual void ObjUpdate();

	void FireBullet();
	bool CheckKeyDown(int keyCode);

public:
	Character() {}
	~Character() {}
};

