#pragma once
#include "Include.h"
#include "RectTransform.h"
#include "DrawManager.h"

// Update..Start..Render..
class Object
{
protected:
	bool _isDie;

	virtual void Update() {}
	virtual void Start() {}
	void ObjStart();
public:
	RectTransform transform;

	void(Object::*UpdateFunction)();

	void ObjUpdate() { (this->*UpdateFunction)(); }
	void Render() { transform.DrawRect(DRAWMANAGER->GetHdc()); }

	RectTransform& GetTransform() { return transform; }
	bool GetIsDie() { return _isDie; }

	virtual void Destroy() {}
	void ObjDestroy() { Destroy(); }

	Object();
	virtual ~Object() {}
};