#pragma once

#include "Include.h"
#include "Singleton.h"
#include "Vector2.h"

#define INPUT_MANAGER (*InputManager::GetInstance())
#define AXIS_SPEED 0.1F

enum KEY_CODE : unsigned short
{
    NONE        = 0x00000000,
    LEFT_ARROW  = 0x00000001,
    RIGHT_ARROW = 0x00000002,
    UP_ARROW    = 0x00000004,   
    DOWN_ARROW  = 0x00000008,
    RETURN      = 0x00000010,
    SPACE       = 0x00000020,
    ESCAPE      = 0x00000040,
    W           = 0x00000080,
    A           = 0x00000100,
    S           = 0x00000200,
    D           = 0x00000400,
    Z           = 0x00000800
};

class InputManager : public Singleton
{
    SINGLETON(InputManager);
private:

	float _axisHorizontal, _axisVertical;
	float _axisRawHorizontal, _axisRawVertical;

    DWORD _inputKey;

    void Start() override;
    void Update() override
    {
        CheckKey();

        if (_inputKey & LEFT_ARROW)
            _axisHorizontal = UpdateAxis(_axisHorizontal, -AXIS_SPEED, 1.0f, -1.0f);
        if (_inputKey & RIGHT_ARROW)
            _axisHorizontal = UpdateAxis(_axisHorizontal, AXIS_SPEED, 1.0f);
        if (_inputKey & UP_ARROW)
            _axisVertical = UpdateAxis(_axisVertical, -AXIS_SPEED, 1.0f, -1.0f);
        if (_inputKey & DOWN_ARROW)
            _axisVertical = UpdateAxis(_axisVertical, AXIS_SPEED, 1.0f);

        if (!(_inputKey & LEFT_ARROW) && !(_inputKey & RIGHT_ARROW))
            _axisHorizontal = Converge(_axisHorizontal, 80);
        if (!(_inputKey & UP_ARROW) && !(_inputKey & DOWN_ARROW))
            _axisVertical = Converge(_axisVertical, 80);
    }

    float UpdateAxis(float axisValue, const float& plusValue, const float &maxValue, const float& correctionValue = 1.0f)
    {
        axisValue += plusValue;

        if (abs(axisValue) >= maxValue)
            axisValue = correctionValue;

        return axisValue;
    }

	float Converge(const float& value, int percent) { return percent * 0.01f * value; }
    void CheckKey();

public:

    DWORD GetKey() { return _inputKey; }

	float GetAxisHorizontal()const	{ return _axisHorizontal; }
	float GetAxisVertical()const     { return _axisVertical; }

    ~InputManager() override;
};