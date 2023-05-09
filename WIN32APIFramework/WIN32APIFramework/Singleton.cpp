#include "Singleton.h"
#include "GameManager.h"

void Singleton::SingletonStart()
{
    UpdateFunction = &Singleton::Update;

    Start();
}

Singleton::~Singleton() {}

void Singleton::Start() {}

Singleton::Singleton()
{
    GAME_MANAGER->PushManagerList(this);
    UpdateFunction = &Singleton::SingletonStart;
}
