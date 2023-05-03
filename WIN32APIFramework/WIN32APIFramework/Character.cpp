#include "Character.h"

void Character::Start()
{
	_keyCode = 0;
	_coolTime = COOLTIME;

	transform.position = Vector2(100, 100);
	transform.SetSize(Vector2(100, 100));
}

void Character::Update()
{
	_coolTime += 0.1f;

	_beforePosition = transform.position;

	transform.position = transform.position + Vector2(INPUTMANAGER->GetAxisHorizontal(), INPUTMANAGER->GetAxisVertical()) * SPEED;

	if (GetAsyncKeyState(VK_SPACE))
		FireBullet();
}


void Character::FireBullet()
{
	if (_coolTime < COOLTIME) return;

	_coolTime = 0;

	Bullet* bullet = new Bullet();
	bullet->transform.position = transform.position;
	bullet->SetDirection(Mathf::GetFromPositionToDirection(transform.position, _beforePosition));
}

bool Character::CheckKeyDown(int keyCode)
{
	if (!GetAsyncKeyState(keyCode)) return false;

	_beforePosition = transform.position;
	_keyCode = keyCode;

	return true;
}
