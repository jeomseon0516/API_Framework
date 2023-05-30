#pragma once
#include "State.h"

class Character;
class Idle;

class Attack : public State
{
public:
    Attack* Start(Object* chr) override;
    void Action(Object* chr) override;

public:
    Attack() {}
    ~Attack() {}
};

