#pragma once
#include "Include.h"
#include "RectTransform.h"

// Update..Start..Render..
class Object
{
private:
	HDC _hdc;
protected:
	RectTransform _transform;

	virtual void ObjUpdate() {}

public:

	virtual void Start() { _hdc = GetDC(g_hWnd); }

	void Update() { ObjUpdate(); }
	void Render() { _transform.DrawRect(_hdc); }

	RectTransform& GetTransform() { return _transform; }

	virtual void Destroy() {}

	Object();
	 ~Object() { Destroy(); }
};

