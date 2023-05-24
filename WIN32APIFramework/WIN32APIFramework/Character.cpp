#include "Character.h"

Character::Character(const Transform& _transform) : Object(_transform) {}
Character::Character() {}
Character::~Character() {}

void Character::Start()
{
    _keyCode = 0;
    _coolTime = COOL_TIME;

    transform.position = Vector2(100, 100);
    transform.SetSize(Vector2(100, 100));
}

void Character::FireBullet()
{
    if (_coolTime < COOL_TIME) return;

    _coolTime = 0;

    Bullet* bullet = (Bullet*)GET_SINGLETON(ObjectPoolManager)->GetGameObject("NormalBullet");

    if (!bullet)
        return;

    bullet->transform.position = transform.position;
    bullet->SetDirection(_direction);
}