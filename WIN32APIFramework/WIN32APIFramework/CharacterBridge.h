#pragma once
#include "LivingObjectBridge.h"
#include "BulletBridge.h"
#include "Bullet.h"

#define COOL_TIME 0.2F

class CharacterBridge : public LivingObjectBridge
{
private:
    Vector2 _beforePosition;

    float _coolTime;
    int _keyCode;

public:
    void Start() override;
    void Update() override
    {
        _coolTime += 0.1f;

        _beforePosition = gameObject->transform.position;

        if (abs(gameObject->GetDirection().x) > 0 && abs(gameObject->GetDirection().y) > 0)
            gameObject->SetLookAt(gameObject->GetDirection());
    }
    void Render() override {}
    void FireBullet(BulletBridge* bulletBridge);
public:
     CharacterBridge();
    ~CharacterBridge();
};

