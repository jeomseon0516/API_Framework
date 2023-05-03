#pragma once
#include "Include.h"
#include "Vector2.h"

class Transform
{
private:
	Vector2 anchor;
	Vector2 size;
public:
	Vector2 position;

	void DrawRect(HDC hdc);
	void DrawEllipse(HDC hdc);
	void AnchorCorrection(float& value);

	Vector2 GetPosition() { return position; }
	void SetPosition(Vector2 position) { this->position = position; }

	Vector2 GetSize() { return size; }

	void SetAnchor(Vector2 anchor) { this->anchor = anchor; }
	void SetSize(Vector2 size) { this->size = size; }

	 Transform(Vector2 position, Vector2 size, Vector2 anchor = Vector2(0.5f, 0.5f));
	 Transform() {}
	~Transform() {}
};

