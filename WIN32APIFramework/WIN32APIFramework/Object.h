#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Include.h"
#include "Transform.h"
#include "DrawManager.h"
#include "ObjectManager.h"

// Update..Start..Render..
class Object
{
protected:

	bool _isDie;
	string _name;

	Vector2 _direction;
	Vector2 _lookAt;

	virtual void Update() {}
	virtual void Start() {}

	void ObjStart();

public:
	Transform transform;

	void(Object::*UpdateFunction)();
	void ObjUpdate() { (this->*UpdateFunction)(); }

	virtual void Render() { transform.DrawRect(DRAWMANAGER->GetHdc()); }
	virtual void OnCollision(Object* object) {}

	void SetDirection(Vector2 direction) { _direction = direction; }

	Transform& GetTransform() { return transform; }
	bool GetIsDie() { return _isDie; }

	virtual void Destroy() {}
	void ObjDestroy() { Destroy(); }

	Object();
	virtual ~Object() {}
};
#endif