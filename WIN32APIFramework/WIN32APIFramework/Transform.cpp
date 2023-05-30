#include "Transform.h"

tagTransform::tagTransform() {}
tagTransform::~tagTransform() {}

void tagTransform::AnchorCorrection(float& value)
{
	if (value < 0)
		value = 0;
	else if (value > 1)
		value = 1;
}

tagTransform::tagTransform(const Vector2& position, const Vector2& size, Vector2 anchor)
{
	this->position = position;
	this->size = size;

	AnchorCorrection(anchor.x);
	AnchorCorrection(anchor.y);

	this->anchor = anchor;
}

