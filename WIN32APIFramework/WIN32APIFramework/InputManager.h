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
    SINGLETON(InputManager);
	float _axisHorizontal, _axisVertical;
	float _axisRawHorizontal, _axisRawVertical;

    float UpdateAxis(float axisValue, float plusValue, float maxValue, float correctionValue = 1.0f)
    {
        axisValue += plusValue;

        if (abs(axisValue) >= maxValue)
            axisValue = correctionValue;

        return axisValue;
    }
	float Converge(float value, int percent) { return percent * 0.01f * value; }

public:
    void Update() override
    {
        if (GetAsyncKeyState(VK_LEFT))
            _axisHorizontal = UpdateAxis(_axisHorizontal, -AXIS_SPEED, 1.0f, -1.0f);
        if (GetAsyncKeyState(VK_RIGHT))
            _axisHorizontal = UpdateAxis(_axisHorizontal, AXIS_SPEED, 1.0f);
        if (GetAsyncKeyState(VK_UP))
            _axisVertical = UpdateAxis(_axisVertical, -AXIS_SPEED, 1.0f, -1.0f);
        if (GetAsyncKeyState(VK_DOWN))
            _axisVertical = UpdateAxis(_axisVertical, AXIS_SPEED, 1.0f);

        if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
            _axisHorizontal = Converge(_axisHorizontal, 80);
        if (!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
            _axisVertical = Converge(_axisVertical, 80);
    }

	float GetAxisHorizontal()	{ return _axisHorizontal; }
	float GetAxisVertical()     { return _axisVertical; }
};

#endif
