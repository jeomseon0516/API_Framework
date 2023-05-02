#include "Object.h"
#include "ObjectManager.h"

void Object::ObjStart()
{
	_isDie = false;

	UpdateFunction = &Object::Update;

	Start();
}

Object::Object()
{
	UpdateFunction = &Object::ObjStart;

	OBJECTMANAGER->PushBackObject(this);
	_transform = RectTransform(Vector2(), Vector2());
}
