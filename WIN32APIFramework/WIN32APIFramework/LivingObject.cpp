#include "LivingObject.h"

LivingObject::LivingObject(const Transform& _transform) : Object(_transform), _speed(0.0f), _direction(Vector2::Zero()), _lookAt(Vector2::Zero()) {}
LivingObject::LivingObject() : _speed(0.0f), _direction(Vector2::Zero()), _lookAt(Vector2::Zero()) /* Default */ {}
LivingObject::~LivingObject() {}