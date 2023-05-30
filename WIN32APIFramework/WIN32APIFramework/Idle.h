#pragma once
#include "State.h"
#include "Attack.h"

class Character;

class Idle : public State<Character>
{
public:
    Idle* Start(Character* chr) override;
    void Action(Character* chr) override;

public:
    Idle() {}
    ~Idle() {}
};