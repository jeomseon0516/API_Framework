#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
public:
    void Start() = 0;
    void Update() = 0;
    void Render() = 0;
    void Destroy() = 0;
public:
    BulletBridge();
    ~BulletBridge();
};