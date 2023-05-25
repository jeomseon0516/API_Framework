#include "Character.h"

Character::Character(const Transform& _transform) : LivingObject(_transform) {}
Character::Character() {}
Character::~Character() {}

void Character::Start()
{
    SetBridge(new CharacterBridge());
    transform.position = Vector2(100, 100);
}

void Character::FireBullet(BulletBridge* bulletBridge)
{
    ((CharacterBridge*)(_bridge))->FireBullet(bulletBridge);
}