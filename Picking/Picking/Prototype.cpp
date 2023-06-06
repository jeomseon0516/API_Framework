#include "Prototype.h"
#include "Object.h"

Prototype::Prototype() { Start(); }
Prototype::~Prototype() {}

void Prototype::Start()
{
    Transform transform = Transform(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f));
}

void Prototype::MakePrototype(Object* obj)
{
    if (_prototypeObject.find(obj->GetLayerName()) != _prototypeObject.end())
    {
        delete obj;
        return;
    }

    _prototypeObject.insert(make_pair(obj->GetLayerName(), obj));
}
