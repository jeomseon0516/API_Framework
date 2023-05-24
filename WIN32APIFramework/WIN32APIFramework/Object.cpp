#pragma once
#include "Object.h"

Object::Object(const Transform& _transform, Bridge* bridge) : transform(_transform), _bridge(bridge)
{
    Init();
}

Object::Object(const Transform& _transform) : transform(_transform), _bridge(nullptr)
{
    Init();
}

Object::Object()
{
	transform = Transform(Vector2(), Vector2());
    Init();
}
Object::~Object() {}

void Object::Init()
{
    _layerName = "Default";
}

Object* Object::ObjStart()
{
	_direction = Vector2::Zero();
	_lookAt    = Vector2::Zero();
    _isDie = DONT;

	Start();
    OBJECT_MANAGER->PushBackObject(_layerName, this);

    return this;
}

void Object::Destroy() 
{
    _isDie = DESTROY;
}

void Object::OnCollision(Object* object) {}

