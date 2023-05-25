#pragma once
#include "Bridge.h"
#include "LivingObject.h"

class LivingObjectBridge : public Bridge
{
protected:
    LivingObject* gameObject;
public:

    void Start() = 0;
    void Update() = 0;
    void Render() = 0;
    void Destroy() override;

    void SetObject(Object* obj) override { gameObject = (LivingObject*)obj; }

public:
     LivingObjectBridge();
    ~LivingObjectBridge();

};

