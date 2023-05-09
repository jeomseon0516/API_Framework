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

void Object::OnCollision(Object* object) {}

void Object::Destroy() {}

void Object::ObjDestroy() { Destroy(); }

Object::Object()
{
	_isDie = false;
	UpdateFunction = &Object::ObjStart;
    _layerName = "Default";

	OBJECT_MANAGER->PushBackObject(this);
	transform = Transform(Vector2(), Vector2());
}

Object::~Object() {}
