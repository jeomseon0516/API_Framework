#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Include.h"
#include "Vector2.h"

class Transform
{
private:
	Vector2 anchor;
	Vector2 size;
public:
	Vector2 position;

    void DrawRect(HDC hdc)
    {
        float leftOffset = size.x * anchor.x;
        float rightOffset = size.x * (1 - anchor.x);

        float topOffset = size.y * anchor.y;
        float bottomOffset = size.y * (1 - anchor.y);

        Rectangle(hdc,
            int(position.x - leftOffset),
            int(position.y - topOffset),
            int(position.x + rightOffset),
            int(position.y + bottomOffset));
    }
    void DrawEllipse(HDC hdc)
    {
        Ellipse(hdc,
            int(position.x - size.x * 0.5f),
            int(position.y - size.y * 0.5f),
            int(position.x + size.x * 0.5f),
            int(position.y + size.y * 0.5f));
    }

	void AnchorCorrection(float& value);

	Vector2 GetPosition() { return position; }
	void SetPosition(Vector2 position) { this->position = position; }

	Vector2 GetSize() { return size; }

	void SetAnchor(Vector2 anchor) { this->anchor = anchor; }
	void SetSize(Vector2 size) { this->size = size; }

	  Transform(Vector2 position, Vector2 size, Vector2 anchor = Vector2::Center());
      Transform();
     ~Transform();
};
#endif

