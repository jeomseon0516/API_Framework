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
			int(position.x - size.x * 0.5f),
			int(position.y - size.y * 0.5f),
			int(position.x + size.x * 0.5f),
			int(position.y + size.y * 0.5f)
		);
	}

	void DrawCycle(HDC hdc)
	{
		Ellipse(hdc,
			int(position.x - size.x * 0.5f),
			int(position.y - size.y * 0.5f),
			int(position.x + size.x * 0.5f),
			int(position.y + size.y * 0.5f)
		);
	}

	Vector2 GetSize()const { return size; }
	tagTransform(const Vector2& _position = Vector2(), const Vector2& _size = Vector2()) :
		position(_position), size(_size) {}
}Transform;

typedef struct tagLocomotion
{
	int maxFrameX;
	int frameY;

	tagLocomotion() : maxFrameX(0), frameY(0) {}
	tagLocomotion(int _maxFrameX, int _frameY) : maxFrameX(_maxFrameX), frameY(_frameY) {}
}Locomotion;

typedef struct tagFrame
{
	Locomotion locomotion;
	int frameX;

	tagFrame() : locomotion(Locomotion()), frameX(0) {}
	tagFrame(const Locomotion& _locomotion, int _frameX) : locomotion(_locomotion), frameX(_frameX) {}
}Frame;