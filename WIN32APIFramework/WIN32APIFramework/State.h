#pragma once
#include "Include.h"

class Object;

template<typename T>
class State
{
public:
    virtual State* Start(T* chr) = 0;
    virtual void Action(T* chr) = 0;
public:
    State() {}
    virtual ~State() {}
};