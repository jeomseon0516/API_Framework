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
		_axisHorizontal = Converge(_axisHorizontal);
	if (!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
		_axisVertical = Converge(_axisVertical);
}

float InputManager::UpdateAxis(float axisValue, float plusValue, float maxValue /* ¾ç¼ö */, float correctionValue)
{
	axisValue += plusValue;

	if (abs(axisValue) >= maxValue)
		axisValue = correctionValue;

	return axisValue;
}

float InputManager::Converge(float value) { return 80.0f * 0.01f * value; }
