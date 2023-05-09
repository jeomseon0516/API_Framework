#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Transform.h"
#include "DrawManager.h"
#include "ObjectManager.h"
#include "Include.h"

// Update..Start..Render..
class Object
{
private:
    void ObjStart();
    void(Object::*UpdateFunction)();
protected:

    bool _isDie;

    string _name;
    string _layerName;

    Vector2 _direction;
    Vector2 _lookAt;

    virtual void Update() {}
    virtual void Start() {}

public:
    Transform transform;
    void ObjUpdate() { (this->*UpdateFunction)(); }

    virtual void Render() { transform.DrawRect(DRAW_MANAGER->GetHdc()); }
    virtual void OnCollision(Object* object);

    string GetLayerName() { return _layerName; }

    void SetDirection(Vector2 direction) { _direction = direction; }

    Transform& GetTransform() { return transform; }
    bool GetIsDie() { return _isDie; }

    virtual void Destroy();
    void ObjDestroy();

    Object();
    virtual ~Object();
};
#endif