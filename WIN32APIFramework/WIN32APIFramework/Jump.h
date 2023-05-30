#pragma once
#include "State.h"
#include "Vector2.h"

#define GRAVITY 0.5f;

class Character;

class Jump : public State<Character>
{
private:
    float _power;
    float _keepY;
    bool _isFall;

public:
    Jump* Start(Character* chr) override;
    void Action(Character* chr) override;
public:
     Jump();
    ~Jump();
};