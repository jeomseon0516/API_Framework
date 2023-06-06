#pragma once
#include "Singleton.h"

class MouseManager
{
	SINGLETON(MouseManager);
private:
	bool isClick;
public:
	bool GetIsClick() { return isClick; }
	void SetIsClick(bool _isClick) { isClick = _isClick; }
	~MouseManager();
};

