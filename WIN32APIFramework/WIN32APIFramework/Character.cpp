#include "Character.h"

Character::Character(const Transform& _transform) : Object(_transform) {}
Character::Character() {}
Character::~Character() {}

void Character::Start()
{
	_keyCode = 0;
	_coolTime = COOL_TIME;

	_direction = Vector2::Zero();
	_lookAt    = Vector2::Zero();

	transform.position = Vector2(100, 100);
	transform.SetSize(Vector2(100, 100));
}

void Character::FireBullet()
{
	if (_coolTime < COOL_TIME) return;

	_coolTime = 0;

	Object* bullet = GET_SINGLETON(Prototype)->GetGameObject("Bullet")->Clone();

    if (!bullet)
        return;

	bullet->ObjStart()->transform.position = transform.position;
	bullet->SetDirection(_direction);
}