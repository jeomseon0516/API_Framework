#include <Windows.h>
#include "Define.h"
#include "RectTransform.h"

void RectTransform::DrawRect(HDC hdc)
{
	float leftOffset  = _size.x * _anchor.x;
	float rightOffset = _size.x * (1 - _anchor.x);

	float topOffset    = _size.y * _anchor.y;
	float bottomOffset = _size.y * (1 - _anchor.y);

	Rectangle(hdc, _position.x - leftOffset, _position.y - topOffset, _position.x + rightOffset, _position.y + bottomOffset);
}

void RectTransform::AnchorCorrection(float& value)
{
	if (value < 0)
		value = 0;
	else if (value > 1)
		value = 1;
}

RectTransform::RectTransform(Vector2 position, Vector2 size, Vector2 anchor)
{
	_position = position;
	_size = size;

	AnchorCorrection(anchor.x);
	AnchorCorrection(anchor.y);

	_anchor = anchor;
}
