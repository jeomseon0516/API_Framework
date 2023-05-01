#pragma once
#include "Vector2.h"

class RectTransform
{
private:

	Vector2 _position;
	Vector2 _anchor;
	Vector2 _size;

public:

	void DrawRect(HDC hdc);
	void AnchorCorrection(float& value);

	RectTransform(Vector2 position, Vector2 size, Vector2 anchor = Vector2(0.5f, 0.5f));

	Vector2 GetPosition() { return _position; }
	void SetPosition(Vector2 position) { _position = position; }

	void SetAnchor(Vector2 anchor) { _anchor = anchor; }
	void SetSize(Vector2 size) { _size = size; }

	 RectTransform() {}
	~RectTransform() {}
};

