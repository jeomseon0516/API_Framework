#include "InputManager.h"

SINGLETON_INIT(InputManager)

InputManager::InputManager()
{
	_axisRawHorizontal = _axisRawVertical = _axisHorizontal = _axisVertical = 0.0f;
}