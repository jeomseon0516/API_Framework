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
protected:

    bool _isDie;

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

    string GetLayerName()const { return _layerName; }
    Object* SetName(const string& name) 
    { 
        _name = name; 
        return this;
    }

    void SetDirection(const Vector2& direction) { _direction = direction; }

    Transform& GetTransform() { return transform; }
    bool GetIsDie()const { return _isDie; }

    virtual void Destroy();
    void ObjDestroy();

    virtual Object* Clone()const { return new Object(*this); }

    Object(const Transform& _transform);
    Object();
    virtual ~Object();
};
#endif