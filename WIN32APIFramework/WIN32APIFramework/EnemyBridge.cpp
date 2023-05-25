#include "EnemyBridge.h"

void EnemyBridge::Start()
{
    gameObject->transform = Transform(Vector2(500, 200), Vector2(30, 30));
    gameObject->SetSpeed(3.0f);

    _target = PLAYER_MANAGER->GetCharacter();
    _coolTime = 0;
    _state = STATE::MOVE;
    _movePoint = Vector2(300, 400);
}

EnemyBridge::EnemyBridge()  {}
EnemyBridge::~EnemyBridge() {}