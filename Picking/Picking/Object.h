#pragma once
#include "Include.h"
#include "Transform.h"

class Object
{
protected:
	string _layerName;
public:
	Transform transform;
public:

	Object* ObjStart() { return this; }
	virtual Object* Start();
	virtual void Update() {}
	virtual void Render() { transform.DrawRect(g_hdc); }
	virtual void Destroy();
	virtual void OnCollision(Object* obj) {}

	string GetLayerName() { return _layerName; }
	Object* Clone() { return new Object(*this); }

public:
	Object();
	virtual ~Object();
};

