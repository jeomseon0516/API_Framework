#pragma once

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "Singleton.h"
#include "Character.h"
#include "Include.h"

#define PLAYER_MANAGER (*PlayerManager::GetInstance())

// 사용자 상태 관리 클래스 게임플레이씬이면 캐릭터를 조작한다.
class PlayerManager : public Singleton
{
    SINGLETON(PlayerManager);
private:
    Character* _character = nullptr;

    void Update() override
    {
        if (_character == nullptr) return;

        _character->SetDirection(Vector2(INPUT_MANAGER->GetAxisHorizontal(), 0.0f));

        if (INPUT_MANAGER->GetKey() & LEFT_CTRL)
            _character->FireBullet(new NormalBullet());
        else if (INPUT_MANAGER->GetKey() & Z)
            _character->FireBullet(new GuideBullet());
    }

public:
    Character* GetCharacter()const { return _character; }
    void SetCharacter(Character* character) { _character = character; }

    ~PlayerManager() override;
};