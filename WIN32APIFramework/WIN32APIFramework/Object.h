#pragma once
#include "Include.h"
#include "RectTransform.h"
#include "DrawManager.h"

// Update..Start..Render..
class Object
{
protected:
	RectTransform _transform;
	bool _isDie;

	virtual void Update() {}
	virtual void Start() {}
	void ObjStart();
public:
	void(Object::*UpdateFunction)();

	void ObjUpdate() { (this->*UpdateFunction)(); }
	void Render() { _transform.DrawRect(DRAWMANAGER->GetHdc()); }

	RectTransform& GetTransform() { return _transform; }
	bool GetIsDie() { return _isDie; }

	virtual void Destroy() {}
	void ObjDestroy() { Destroy(); }

	Object();
	 ~Object() {}
};