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
    
    motionList.insert(make_pair("Idle",       Locomotion(0, 7)));
    motionList.insert(make_pair("Run",        Locomotion(1, 3)));
    motionList.insert(make_pair("Attack",     Locomotion(5, 4)));
    motionList.insert(make_pair("Acrobatics", Locomotion(4, 5)));
    motionList.insert(make_pair("Jump",       Locomotion(3, 3)));

    _state = new Idle();

    transform.position = Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f;
}

void Character::FireBullet(BulletBridge* bulletBridge)
{
    ((CharacterBridge*)(_bridge))->FireBullet(bulletBridge);
}