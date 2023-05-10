#include "InputManager.h"

InputManager::InputManager() {}
InputManager::~InputManager() {}

void InputManager::Start()
{
    _axisRawHorizontal = _axisRawVertical = _axisHorizontal = _axisVertical = 0.0f;
    _inputKey = NONE;
}

void InputManager::CheckKey()
{
    _inputKey = NONE;

    if (GetAsyncKeyState(VK_LEFT))
        _inputKey |= LEFT_ARROW;
    if (GetAsyncKeyState(VK_RIGHT))
        _inputKey |= RIGHT_ARROW;
    if (GetAsyncKeyState(VK_UP))
        _inputKey |= UP_ARROW;
    if (GetAsyncKeyState(VK_DOWN))
        _inputKey |= DOWN_ARROW;
    if (GetAsyncKeyState(VK_RETURN))
        _inputKey |= RETURN;
    if (GetAsyncKeyState(VK_SPACE))
        _inputKey |= SPACE;
    if (GetAsyncKeyState(VK_ESCAPE))
        _inputKey |= ESCAPE;
    if (GetAsyncKeyState('W'))
        _inputKey |= W;
    if (GetAsyncKeyState('A'))
        _inputKey |= A;
    if (GetAsyncKeyState('S'))
        _inputKey |= S;
    if (GetAsyncKeyState('D'))
        _inputKey |= D;
}