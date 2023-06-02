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

	virtual Object* Start();
	virtual void Update() {}
	virtual void Render() { transform.DrawRect(g_hdc); }
	virtual void Destroy();

	string GetLayerName() { return _layerName; }

public:
	Object();
	virtual ~Object();
};

