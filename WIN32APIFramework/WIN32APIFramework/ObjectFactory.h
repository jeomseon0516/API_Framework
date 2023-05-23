#pragma once
#include "Object.h"

#define OBJECT_FACTORY(T) ObjectFactory<T>
#define CREATE_OBJECT(T) (new T())->ObjStart();

#define CREATE_OBJECT(T, X, Y)\
[](const float& _x, const float& _y)\
{\
    T* obj = (new T())->ObjStart();\
    obj->transform.position = Vector2(_x, _y);\
    return obj;\
}(X, Y)

#define CREATE_OBJECT(T, POSITION)\
[](const Vector2& _position)\
{\
    T* obj = (new T())->ObjStart();\
    obj->transform.position = _position;\
    return obj;\
}(POSITION)

template <typename T>
class ObjectFactory
{
public:
    static Object* CreateObject()
    {
        Object* obj = new T();
        return obj->ObjStart();
    }

    static Object* CreateObject(const float& _x, const float& _y)
    {
        Object* obj = new T();
        obj->ObjStart();
        obj->transform.position = Vector2(_x, _y);

        return obj;
    }

    static Object* CreateObject(const Vector2& position)
    {
        Object* obj = new T();
        obj->ObjStart();
        obj->transform.position = position;

        return obj;
    }
};