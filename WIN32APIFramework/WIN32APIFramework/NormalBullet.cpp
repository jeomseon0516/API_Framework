#include "NormalBullet.h"

NormalBullet::NormalBullet()  {}
NormalBullet::~NormalBullet() {}

void NormalBullet::Start()
{
    gameObject->SetSpeed(20.0f);
}
