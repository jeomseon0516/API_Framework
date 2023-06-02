#pragma once
#include "Include.h"
#include "Vector2.h"

typedef struct tagTransform
{
	Vector2	position;
	Vector2 size;

	void DrawRect(HDC hdc)
	{
		Rectangle(hdc,
			position.x - size.x * 0.5f,
			position.y - size.y * 0.5f,
			position.x + size.x * 0.5f,
			position.y + size.y * 0.5f
		);
	}

	void DrawCycle(HDC hdc)
	{
		Ellipse(hdc,
			position.x - size.x * 0.5f,
			position.y - size.y * 0.5f,
			position.x + size.x * 0.5f,
			position.y + size.y * 0.5f
		);
	}

	tagTransform(const Vector2& _position = Vector2(), const Vector2& _size = Vector2()) :
		position(_position), size(_size) {}
}Transform;