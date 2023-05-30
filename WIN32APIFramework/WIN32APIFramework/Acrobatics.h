#pragma once
#include "State.h"

class Character;

class Acrobatics : public State<Character>
{
public:
    Acrobatics* Start(Character* chr) override;
    void Action(Character* chr) override;
public:
    Acrobatics();
    ~Acrobatics();
};

