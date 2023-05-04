#pragma once
#include "Object.h"

void Object::ObjStart()
{
	UpdateFunction = &Object::Update;

	_direction = Vector2::Zero();
	_lookAt    = Vector2::Zero();

	Start();
}

Object::Object()
{
	_isDie = false;
	UpdateFunction = &Object::ObjStart;

	OBJECTMANAGER->PushBackObject(this);
	transform = Transform(Vector2(), Vector2());
}
