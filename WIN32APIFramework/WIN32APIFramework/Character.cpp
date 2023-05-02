#include "Character.h"
#include "Mathf.h"

void Character::Update()
{
	_coolTime += 0.1f;

	_transform.SetPosition(_transform.GetPosition() + Vector2(INPUTMANAGER->GetAxisHorizontal(), INPUTMANAGER->GetAxisVertical()) * SPEED);

	if (GetAsyncKeyState(VK_SPACE))
		FireBullet();
}

void Character::Start()
{
	_keyCode = 0;
	_coolTime = COOLTIME;

	_transform.SetPosition(Vector2(100, 100));
	_transform.SetSize(Vector2(100, 100));
}

void Character::FireBullet()
{
	if (_coolTime < COOLTIME) return;

	_coolTime = 0;

	Bullet* bullet = new Bullet();
	bullet->GetTransform().SetPosition(_transform.GetPosition());
	bullet->SetDirection(Mathf::GetFromPositionToDirection(_transform.GetPosition(), _beforePosition));
}

bool Character::CheckKeyDown(int keyCode)
{
	if (!GetAsyncKeyState(keyCode)) return false;

	_beforePosition = _transform.GetPosition();
	_keyCode = keyCode;

	return true;
}
