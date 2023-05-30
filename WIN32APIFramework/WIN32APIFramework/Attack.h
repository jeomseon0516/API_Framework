#pragma once
#include "State.h"
#include "Idle.h"

class Character;

class Attack : public State<Character>
{
public:
    Attack* Start(Character* chr) override;
    void Action(Character* chr) override;

public:
    Attack() {}
    ~Attack() {}
};

