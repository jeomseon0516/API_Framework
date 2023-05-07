#pragma once
#include "Scene.h"
#include "Enemy.h"
#include "PlayerManager.h"

class Main : public Scene
{
public:
    void Update() override {}

     Main() 
     { 
         PLAYER_MANAGER->SetCharacter(new Character); 
         (new Enemy())->SetTarget(PLAYER_MANAGER->GetCharacter());
     }
    ~Main() {}
};

