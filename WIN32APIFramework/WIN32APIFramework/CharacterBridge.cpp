#include "CharacterBridge.h"

void CharacterBridge::Start()
{
    gameObject->SetSpeed(10.0f);
    gameObject->transform.SetSize(Vector2(97, 71));

    _keyCode = 0;
    _coolTime = COOL_TIME;
}

void CharacterBridge::FireBullet(BulletBridge* bulletBridge)
{
    if (_coolTime < COOL_TIME) return;

    _coolTime = 0;

    Bullet* bullet = (Bullet*)GET_SINGLETON(ObjectPoolManager)->GetGameObject("NormalBullet");

    if (!bullet)
        return;

    bullet->transform.position = gameObject->transform.position;
    bullet->SetDirection(gameObject->GetDirection());
    bullet->SetBridge(bulletBridge);
    /*
        Object 클래스의 SetBridge는 모든 Bridge객체를 받아 올 수 있으므로 상속받은 Bullet에서는
        기존의 SetBridge함수를 private으로 override후 함수를 새로 정의
    */
}

CharacterBridge::CharacterBridge() {}

CharacterBridge::~CharacterBridge() {}
