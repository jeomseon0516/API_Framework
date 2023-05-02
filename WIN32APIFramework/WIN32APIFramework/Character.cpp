#include "Character.h"
#include "Mathf.h"

void Character::Update()
{
	_coolTime += 0.1f;

	if (CheckKeyDown(VK_UP))
		_transform.SetPosition(Vector2(_transform.GetPosition().x, _transform.GetPosition().y - SPEED));

	if (CheckKeyDown(VK_DOWN))
		_transform.SetPosition(Vector2(_transform.GetPosition().x, _transform.GetPosition().y + SPEED));

	if (CheckKeyDown(VK_LEFT))
		_transform.SetPosition(Vector2(_transform.GetPosition().x - SPEED, _transform.GetPosition().y));

	if (CheckKeyDown(VK_RIGHT))
		_transform.SetPosition(Vector2(_transform.GetPosition().x + SPEED, _transform.GetPosition().y));

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
