#pragma once
#include "State.h"

class Acrobatics : public State
{
public:
    Acrobatics* Start(Object* chr) override;
    void Action(Object* chr) override;
public:
    Acrobatics();
    ~Acrobatics();
};

