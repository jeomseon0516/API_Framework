#pragma once

#include "Singleton.h"
#include "Vector2.h"

#define INPUTMANAGER InputManager::GetInstance()
#define AXIS_SPEED 0.1F

class InputManager : public Singleton<InputManager>
{
private:
	friend class Singleton<InputManager>;

	float _axisHorizontal, _axisVertical;
	float _axisRawHorizontal, _axisRawVertical;

	float UpdateAxis(float axisValue, float plusValue, float maxValue, float correctionValue = 1.0f);
	float Converge(float value, int percent);

public:
	virtual void Update();

	float GetAxisHorizontal()	{ return _axisHorizontal; }
	float GetAxisVertical()     { return _axisVertical; }

private:
	InputManager() { _axisHorizontal = _axisVertical = 0.0f; }
};
