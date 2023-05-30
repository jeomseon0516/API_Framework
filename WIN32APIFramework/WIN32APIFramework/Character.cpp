#include "Character.h"

Character::Character(const Transform& _transform) : LivingObject(_transform)
{
    _layerName = "Character";
}

Character::Character()
{
    _layerName = "Character";
}

Character::~Character() {}

void Character::Start()
{
    SetBridge(new CharacterBridge());
    
    motionList.insert(make_pair("Idle",       Locomotion(0, 6)));
    motionList.insert(make_pair("Run",        Locomotion(1, 6)));
    motionList.insert(make_pair("Attack",     Locomotion(5, 3)));
    motionList.insert(make_pair("Acrobatics", Locomotion(4, 4)));
    motionList.insert(make_pair("Jump",       Locomotion(2, 2)));
    motionList.insert(make_pair("Fall",       Locomotion(3, 2)));

    _isFlipX = false;
    _state = new Idle();

    transform.position = Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f;
}

void Character::FireBullet(BulletBridge* bulletBridge)
{
    ((CharacterBridge*)(_bridge))->FireBullet(bulletBridge);
}