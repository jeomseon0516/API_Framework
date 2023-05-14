#pragma once
// 

class Base
{
public:

	virtual void Start() {}
	virtual void Update() {}
	virtual void Destroy() {}

	 Base() {}
	 ~Base() { Destroy(); }
};

