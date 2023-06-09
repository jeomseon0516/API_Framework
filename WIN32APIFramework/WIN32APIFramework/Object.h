#pragma once

#include "Transform.h"
#include "DrawManager.h"
#include "ObjectManager.h"
#include "ImageManager.h"
#include "Include.h"
#include "Bridge.h"

enum class DESTROY_STATE : unsigned char
{
    DESTROY = 0x00000000,
    POOL    = 0x00000001,
    DONT    = 0x00000002
};

// .. Update..Start..Render..
class Object
{
protected:
    Bridge* _bridge;
    Frame _frame;
    ULONGLONG _time;

    DESTROY_STATE _destroyState;

    string _layerName; // .. PrimaryKey

    map<string, Bitmap*>* m_imageList;
    map<string, Locomotion> motionList;

    void Init();

    virtual void Start() {}
    virtual void Update() {}

public:

    Object* ObjStart();
    Transform transform;

    virtual void Render() { transform.DrawRect(DRAW_MANAGER->GetMemDC()); }
    virtual void OnCollision(Object* object);
    virtual void Destroy();

    virtual void ObjUpdate() { Update(); }
    string GetLayerName()const { return _layerName; }

    Object* SetName(const string& name)
    {
        _layerName = name;
        return this;
    }

    DESTROY_STATE GetDestroyState()const { return _destroyState; }
    void SetDestroyState(const DESTROY_STATE isDestroy) { _destroyState = isDestroy; }

    Transform& GetTransform() { return transform; }

    virtual void SetBridge(Bridge* bridge)
    {
        if (_bridge) delete _bridge;
        _bridge = bridge;
        _bridge->SetObject(this);
        _bridge->Start();
    }

    virtual Object* Clone()const { return new Object(*this); }

    Object(const Transform& _transform);
    Object();
    virtual ~Object();
};