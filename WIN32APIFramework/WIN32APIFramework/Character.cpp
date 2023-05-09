#include "Character.h"

Character::Character() {}
Character::~Character() {}

void Character::Start()
{
	_keyCode = 0;
	_coolTime = COOLTIME;

	_direction = Vector2::Zero();
	_lookAt = Vector2::Zero();

	transform.position = Vector2(100, 100);
	transform.SetSize(Vector2(100, 100));
}

void Character::FireBullet()
{
	if (_coolTime < COOLTIME) return;

	_coolTime = 0;

	Bullet* bullet = new Bullet();
	bullet->transform.position = transform.position;
	bullet->SetDirection(_lookAt);
}