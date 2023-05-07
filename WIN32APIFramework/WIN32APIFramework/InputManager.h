#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Include.h"
#include "Singleton.h"
#include "Vector2.h"

#define INPUT_MANAGER InputManager::GetInstance()
#define AXIS_SPEED 0.1F

class InputManager : public Singleton
{
	SINGLETON(InputManager)
	float _axisHorizontal, _axisVertical;
	float _axisRawHorizontal, _axisRawVertical;

	float UpdateAxis(float axisValue, float plusValue, float maxValue, float correctionValue = 1.0f);
	float Converge(float value, int percent) { return percent * 0.01f * value; }

public:
	void Update() override;

	float GetAxisHorizontal()	{ return _axisHorizontal; }
	float GetAxisVertical()     { return _axisVertical; }
};

#endif
