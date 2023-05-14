#include "Singleton.h"
#include "GameManager.h"

Singleton::Singleton()
{
    GAME_MANAGER->PushManagerList(this);
    UpdateFunction = &Singleton::SingletonStart;
}

Singleton::~Singleton() {}

void Singleton::SingletonStart()
{
    UpdateFunction = &Singleton::Update;

    Start();
}

void Singleton::Start() {}