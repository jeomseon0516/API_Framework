#pragma once
#include "Object.h"

class LivingObject : public Object
{
protected:
    Vector2 _direction;
    Vector2 _lookAt;

    float _speed;
private:
    void Move() { transform.position += _direction * _speed; }
public:
    void ObjUpdate() override final
    {
        if (_time + _frame.frameTime < GetTickCount64())
        {
            _time = GetTickCount64();
            ++_frame.countX;
        }

        Object::ObjUpdate();
        Move();
    }

    Vector2 GetLookAt()const { return _lookAt; }
    void SetLookAt(const Vector2& lookAt) { _lookAt = lookAt; }

    Vector2 GetDirection() { return _direction; }
    void SetDirection(const Vector2& direction) { _direction = direction; }

    float GetSpeed()const { return _speed; }
    void SetSpeed(const float& speed) { _speed = speed; }

public:
     LivingObject(const Transform& _transform);
     LivingObject();
    ~LivingObject();
};

