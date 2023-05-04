#include "InputManager.h"

SINGLETON_INIT(InputManager)

InputManager::InputManager()
{
	_axisRawHorizontal = _axisRawVertical = _axisHorizontal = _axisVertical = 0.0f;
}

void InputManager::Update()
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

float InputManager::UpdateAxis(float axisValue, float plusValue, float maxValue, float correctionValue)
{
	axisValue += plusValue;

	if (abs(axisValue) >= maxValue)
		axisValue = correctionValue;

	return axisValue;
}