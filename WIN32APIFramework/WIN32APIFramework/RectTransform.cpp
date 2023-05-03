#include "RectTransform.h"

void RectTransform::DrawRect(HDC hdc)
{
	float leftOffset = size.x * anchor.x;
	float rightOffset = size.x * (1 - anchor.x);

	float topOffset = size.y * anchor.y;
	float bottomOffset = size.y * (1 - anchor.y);

	Rectangle(hdc,
		(int)(position.x - leftOffset),
		(int)(position.y - topOffset),
		(int)(position.x + rightOffset),
		(int)(position.y + bottomOffset));
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
	this->position = position;
	this->size = size;

	AnchorCorrection(anchor.x);
	AnchorCorrection(anchor.y);

	this->anchor = anchor;
}
