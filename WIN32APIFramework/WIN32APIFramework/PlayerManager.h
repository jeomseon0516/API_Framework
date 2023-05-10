#pragma once
#ifndef __PLAYER_MANAGER_H__
#define __PLAYER_MANAGER_H__

#include "Singleton.h"
#include "Include.h"
#include "Character.h"

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
		_character->SetDirection(Vector2(INPUT_MANAGER->GetAxisHorizontal(), INPUT_MANAGER->GetAxisVertical()));

        if (INPUT_MANAGER->GetKey() & SPACE)
            _character->FireBullet();
	}

public:
    Character* GetCharacter() { return _character; }
	void SetCharacter(Character* character) { _character = character; }

    ~PlayerManager() override;
};
#endif