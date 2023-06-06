#include "Singleton.h"

Singleton::Singleton()
{
    UpdateFunction = &Singleton::SingletonStart;
}

Singleton::~Singleton() {}

void Singleton::SingletonStart()
{
    UpdateFunction = &Singleton::Update;
    Start();
}

void Singleton::Start() {}