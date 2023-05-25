#include "LivingObjectBridge.h"
#include "LivingObject.h"

LivingObjectBridge::LivingObjectBridge() : gameObject((LivingObject*)GetGameObject()) {}
LivingObjectBridge::~LivingObjectBridge() {}

void LivingObjectBridge::Destroy()
{
    gameObject->Destroy();
}
