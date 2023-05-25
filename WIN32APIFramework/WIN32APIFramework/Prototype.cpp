#include "Prototype.h"
#include "Character.h"
#include "Bullet.h"
#include "Enemy.h"

Prototype::Prototype() { Start(); }
Prototype::~Prototype() {}

void Prototype::Start()
{
    Transform transform = Transform(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f));

    string key = "Character";
    _prototypeObject.insert(make_pair(key, (new Character(transform))));

    key = "NormalBullet";
    _prototypeObject.insert(make_pair(key, (new Bullet(transform))));

    key = "Enemy";
    _prototypeObject.insert(make_pair(key, (new Enemy(transform))));
}