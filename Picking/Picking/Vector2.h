#pragma once

typedef struct tagVector2
{
	float x, y;

	tagVector2 operator+(const tagVector2& value)  { return tagVector2(x + value.x, y + value.y); }
	tagVector2 operator*(const float& value)  { return tagVector2(x * value, y * value); }
	tagVector2 operator+=(const tagVector2& value) { return tagVector2(x += value.x, y += value.y); }

	tagVector2(float _x = 0, float _y = 0) : x(_x), y(_y) {}
}Vector2;