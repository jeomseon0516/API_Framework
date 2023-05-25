#include "GuideBullet.h"
#include "PlayerManager.h"

GuideBullet::GuideBullet()  {}
GuideBullet::~GuideBullet() {}

void GuideBullet::Start()
{
    BulletBridge::Start();
    gameObject->SetSpeed(3.0f);
    _target = PLAYER_MANAGER->GetCharacter();
}