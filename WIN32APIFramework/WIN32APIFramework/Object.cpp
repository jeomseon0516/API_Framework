#pragma once
#include "Object.h"

Object::Object(const Transform& _transform) : transform(_transform)
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
    _isDie = false;
    _layerName = "Default";
}

Object* Object::ObjStart()
{
	_direction = Vector2::Zero();
	_lookAt    = Vector2::Zero();

	Start();
    OBJECT_MANAGER->PushBackObject(_layerName, this);

    return this;
}

void Object::OnCollision(Object* object) {}
void Object::Destroy() {}
void Object::ObjDestroy() { Destroy(); }


