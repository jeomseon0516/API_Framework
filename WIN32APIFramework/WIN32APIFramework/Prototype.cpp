#include "Prototype.h"
#include "Character.h"
#include "Bullet.h"
#include "Enemy.h"

Prototype::Prototype() { Start(); }
Prototype::~Prototype() {}

void Prototype::Start()
{
    Transform transform = Transform(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f));

    MakePrototype(new Character(transform));
    MakePrototype(new Enemy(transform));
    MakePrototype(new Bullet(transform));
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
