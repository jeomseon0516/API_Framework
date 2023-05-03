#pragma once
#include "Object.h"
#include "ObjectManager.h"

void Object::ObjStart()
{
	UpdateFunction = &Object::Update;

	Start();
}

Object::Object()
{
	_isDie = false;
	UpdateFunction = &Object::ObjStart;

	OBJECTMANAGER->PushBackObject(this);
	transform = Transform(Vector2(), Vector2());
}
