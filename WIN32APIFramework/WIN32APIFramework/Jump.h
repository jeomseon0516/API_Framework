#pragma once
#include "State.h"
#include "Vector2.h"

#define GRAVITY 0.5f;

class Jump : public State
{
private:
    float _power;
    Vector2 _startPosition;

public:
    Jump* Start(Object* chr) override;
    void Action(Object* chr) override;

public:
    Jump();
    ~Jump();
};

