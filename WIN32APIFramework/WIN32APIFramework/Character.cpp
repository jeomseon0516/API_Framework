#include "Character.h"

void Character::Start()
{
	_keyCode = 0;
	_coolTime = COOLTIME;

	_direction = Vector2::Zero();
	_lookAt = Vector2::Zero();

	transform.position = Vector2(100, 100);
	transform.SetSize(Vector2(100, 100));
}

void Character::Update()
{
	_coolTime += 0.1f;

	_beforePosition = transform.position;

	_direction = Vector2(INPUT_MANAGER->GetAxisHorizontal(), INPUT_MANAGER->GetAxisVertical());

	if (abs(_direction.x) > 0 && abs(_direction.y) > 0)
		_lookAt = _direction;

	transform.position = transform.position + _direction * SPEED;

	if (GetAsyncKeyState(VK_SPACE))
		FireBullet();
}

void Character::FireBullet()
{
	if (_coolTime < COOLTIME) return;

	_coolTime = 0;

	Bullet* bullet = new Bullet();
	bullet->transform.position = transform.position;
	bullet->SetDirection(_lookAt);
}

bool Character::CheckKeyDown(int keyCode)
{
	if (!GetAsyncKeyState(keyCode)) return false;

	_beforePosition = transform.position;
	_keyCode = keyCode;

	return true;
}
