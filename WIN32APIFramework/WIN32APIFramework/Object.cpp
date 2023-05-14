#pragma once
#include "Object.h"

Object::Object()
{
	_isDie = false;
	UpdateFunction = &Object::ObjStart;
    _layerName = "Default";

	transform = Transform(Vector2(), Vector2());
    OBJECT_MANAGER->InitList(this);
}
Object::~Object() {}

void Object::ObjStart()
{
	UpdateFunction = &Object::Update;

	_direction = Vector2::Zero();
	_lookAt    = Vector2::Zero();

	Start();
    OBJECT_MANAGER->PushBackObject(_layerName, this);
}

void Object::OnCollision(Object* object) {}
void Object::Destroy() {}
void Object::ObjDestroy() { Destroy(); }

