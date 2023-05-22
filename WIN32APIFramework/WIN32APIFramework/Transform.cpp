#include "Transform.h"

Transform::Transform() {}
Transform::~Transform() {}

void Transform::AnchorCorrection(float value)
{
	if (value < 0)
		value = 0;
	else if (value > 1)
		value = 1;
}

Transform::Transform(const Vector2& position, const Vector2& size, const Vector2& anchor)
{
	this->position = position;
	this->size = size;

	AnchorCorrection(anchor.x);
	AnchorCorrection(anchor.y);

	this->anchor = anchor;
}

