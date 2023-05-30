#pragma once
#include "Include.h"

class Object;

class State
{
private:

public:
    virtual State* Start(Object* chr)  = 0;
    virtual void Action(Object* chr) = 0;
public:
    State() {}
    virtual ~State() {}
};

