#include "Main.h"

Main::Main()
{
    PLAYER_MANAGER->SetCharacter(new Character);
    (new Enemy())->SetTarget(PLAYER_MANAGER->GetCharacter());
}

Main::~Main() {}
