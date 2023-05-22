#include "Main.h"

Main::Main()
{
    Object* character = GET_SINGLETON(Prototype)->GetGameObject("Character")->Clone();

    if (character)
        PLAYER_MANAGER->SetCharacter((Character*)character->ObjStart());

    Object* enemy = GET_SINGLETON(Prototype)->GetGameObject("Enemy")->Clone();

    if (enemy)
        ((Enemy*)(enemy->ObjStart()))->SetTarget(PLAYER_MANAGER->GetCharacter());
}

Main::~Main() {}
