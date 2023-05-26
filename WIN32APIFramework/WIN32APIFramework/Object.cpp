#pragma once
#include "Object.h"

Object::Object(const Transform& _transform) : transform(_transform), _bridge(nullptr), m_imageList(IMAGE_MANAGER->GetImageList())
{
    Init();
}

Object::Object() : transform(Transform(Vector2(), Vector2())), _bridge(nullptr)
{
    Init();
}

Object::~Object() 
{
    if (!_bridge) return;
    delete _bridge;
}

void Object::Init()
{
    _layerName = "Default";
}

Object* Object::ObjStart()
{
    _destroyState = DESTROY_STATE::DONT;

	Start();
    OBJECT_MANAGER->PushBackObject(_layerName, this);

    return this;
}

void Object::Destroy() 
{
    _destroyState = DESTROY_STATE::DESTROY;
}

void Object::OnCollision(Object* object) {}