#pragma once

#include "Singleton.h"
#include "Vector2.h"

#define INPUTMANAGER InputManager::GetInstance()

class InputManager : public Singleton<InputManager>
{
private:
	friend class Singleton<InputManager>;

public:
	
	Vector2 _axisHorizontal, _axisVertical;
	Vector2 _axisRawHorizontal, _axisRawVertical;

	virtual void Update();

private:
	InputManager() {}
};
