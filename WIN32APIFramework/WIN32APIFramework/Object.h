#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Transform.h"
#include "DrawManager.h"
#include "ObjectManager.h"
#include "Include.h"
#include "Bridge.h"

// Update..Start..Render..

enum IS_DESTROY : unsigned char
{
    DESTROY = 0x00000000,
    POOL,
    DONT
};

class Object
{
protected:
    Bridge* _bridge;

    IS_DESTROY _isDie;

    string _name;
    string _layerName;

    Vector2 _direction;
    Vector2 _lookAt;

    void Init();
    virtual void Start() {}

public:

    Object* ObjStart();
    virtual void Update() {}

    Transform transform;

    virtual void Render() { transform.DrawRect(DRAW_MANAGER->GetHdc()); }
    virtual void OnCollision(Object* object);
    virtual void Destroy();

    string GetLayerName()const { return _layerName; }

    Object* SetName(const string& name) 
    { 
        _name = name; 
        return this;
    }

    Vector2 GetLookAt()const { return _lookAt; }
    void SetLookAt(const Vector2& lookAt) { _lookAt = lookAt; }

    Vector2 GetDirection() { return _direction; }
    void SetDirection(const Vector2& direction) { _direction = direction; }

    IS_DESTROY GetIsDie()const { return _isDie; }
    void SetIsDie(const IS_DESTROY isDestroy) { _isDie = isDestroy; }

    Transform& GetTransform() { return transform; }
    void SetBridge(Bridge* bridge) { _bridge = bridge; }

    virtual Object* Clone()const { return new Object(*this); }

    Object(const Transform& _transform, Bridge* bridge);
    Object(const Transform& _transform);
    Object();
    virtual ~Object();
};
#endif