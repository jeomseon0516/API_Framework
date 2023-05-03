#include "InputManager.h"

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

float InputManager::Converge(float value, int percent) { return percent * 0.01f * value; }
