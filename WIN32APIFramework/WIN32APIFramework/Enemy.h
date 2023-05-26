#pragma once
#include "LivingObject.h"
#include "EnemyBridge.h"

class Enemy : public LivingObject
{
private:

	void Start() override;
    void Idle() {}

public:

    void Update() override
    {
        _bridge->Update();
    }

    void OnCollision(Object* obj) override;
    void Destroy() override;

	void Render() override { transform.DrawEllipse((*m_imageList)["Buffer"]->GetMemDC()); }
	void SetTarget(Object* target) { ((EnemyBridge*)_bridge)->SetTarget(target); }
     
    Enemy* Clone()const override { return new Enemy(*this); }

     Enemy(const Transform& _transform);
     Enemy();
    ~Enemy() override;
};