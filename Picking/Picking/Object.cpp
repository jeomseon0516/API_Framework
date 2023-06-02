#include "Object.h"

Object::Object() {}
Object::~Object() {}

Object* Object::Start()
{
	_layerName = "Default";
	return this;
}

void Object::Destroy()
{

}