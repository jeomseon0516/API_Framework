#pragma once
#include "Include.h"

class Object;

template<typename T>
class State
{
private:

public:
    virtual State* Start(T* chr) = 0;
    virtual void Action(T* chr) = 0;

    void main() {}
public:
    State() {}
    virtual ~State() {}
};

