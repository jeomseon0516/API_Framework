#pragma once
#include "Include.h"
#include "Transform.h"
#include "DrawManager.h"

// Update..Start..Render..
class Object
{
protected:
	bool _isDie;
	string _name;

	virtual void Update() {}
	virtual void Start() {}

	void ObjStart();
public:
	Transform transform;

	void(Object::* UpdateFunction)();

	void ObjUpdate() { (this->*UpdateFunction)(); }
	virtual void Render() { transform.DrawRect(DRAWMANAGER->GetHdc()); }

	virtual void OnCollision(Object* object) {}

	Transform& GetTransform() { return transform; }
	bool GetIsDie() { return _isDie; }

	virtual void Destroy() {}
	void ObjDestroy() { Destroy(); }

	Object();
	virtual ~Object() {}
};