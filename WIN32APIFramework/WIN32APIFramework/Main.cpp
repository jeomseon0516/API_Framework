#include "Main.h"

Main::Main()
{
    Object* character = GET_SINGLETON(ObjectPoolManager)->GetGameObject("Character");

    if (character)
        PLAYER_MANAGER->SetCharacter((Character*)character);

    GET_SINGLETON(ObjectPoolManager)->GetGameObject("Enemy");
}

Main::~Main() {}
