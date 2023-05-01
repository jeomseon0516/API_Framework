#include "Character.h"
#include "Mathf.h"

void Character::Start()
{
	Object::Start();
	_keyCode = 0;
	_coolTime = COOLTIME;

	_transform.SetPosition(Vector2(100, 100));
	_transform.SetSize(Vector2(100, 200));
}

void Character::ObjUpdate()
{
	_coolTime += 0.1f;

	_beforePosition = _transform.GetPosition();
	// yรเ ตฺมýศ๛
	if (CheckKeyDown(VK_UP))
		_transform.SetPosition(Vector2(_transform.GetPosition().x, _transform.GetPosition().y - SPEED));

	else if (CheckKeyDown(VK_DOWN))
		_transform.SetPosition(Vector2(_transform.GetPosition().x, _transform.GetPosition().y + SPEED));

	else if (CheckKeyDown(VK_LEFT))
		_transform.SetPosition(Vector2(_transform.GetPosition().x - SPEED, _transform.GetPosition().y));

	else if (CheckKeyDown(VK_RIGHT))
		_transform.SetPosition(Vector2(_transform.GetPosition().x + SPEED, _transform.GetPosition().y));

	
	if (GetAsyncKeyState(VK_SPACE))
		FireBullet();
}

void Character::FireBullet()
{
	if (_coolTime < COOLTIME) return;

	_coolTime = 0;

	Bullet* bullet = new Bullet();
	bullet->Start();
	bullet->GetTransform().SetPosition(_transform.GetPosition());
	bullet->SetDirection(Mathf::GetFromPositionToDirection(_beforePosition, _transform.GetPosition()));
}

bool Character::CheckKeyDown(int keyCode)
{
	if (!GetAsyncKeyState(keyCode)) return false;
	_keyCode = keyCode;

	return true;
}
