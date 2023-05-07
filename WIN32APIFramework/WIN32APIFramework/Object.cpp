#pragma once
#include "Object.h"

void Object::ObjStart()
{
	UpdateFunction = &Object::Update;

	_direction = Vector2::Zero();
	_lookAt    = Vector2::Zero();

	Start();

    COLLISION_MANAGER->MakeFromKeyCollisionList(_layerName);
}

Object::Object()
{
	_isDie = false;
	UpdateFunction = &Object::ObjStart;
    _layerName = "Default";

	OBJECT_MANAGER->PushBackObject(this);
	transform = Transform(Vector2(), Vector2());
}
