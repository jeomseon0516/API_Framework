#pragma once
#include "State.h"

class Character;
class Attack;

class Idle : public State
{
public:
    Idle* Start(Object* chr) override;
    void Action(Object* chr) override;

public:
    Idle() {}
    ~Idle() {}
};
