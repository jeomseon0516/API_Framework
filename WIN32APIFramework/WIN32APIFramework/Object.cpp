#include "Object.h"
#include "ObjectManager.h"

Object::Object()
{
	OBJECTMANAGER->PushBackObject(this);
	_transform = RectTransform(Vector2(), Vector2());
}
