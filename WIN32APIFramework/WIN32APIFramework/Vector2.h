#pragma once

class Vector2
{
public:
	float x, y;

	Vector2 operator+(Vector2 value) { return Vector2(x + value.x, y + value.y); }
	Vector2 operator-(Vector2 value) { return Vector2(x - value.x, y - value.y); }
	Vector2 operator*(Vector2 value) { return Vector2(x * value.x, y * value.y); }
	Vector2 operator*(float value)   { return Vector2(x * value, x * value); }

	Vector2 operator/(Vector2 value) { return Vector2(x / value.x, y / value.y); }
	Vector2 operator/(float value)   { return Vector2(x / value, y / value); }

	static Vector2 Zero() { return Vector2(0, 0); }

	Vector2() { *this = Vector2::Zero(); }
	 Vector2(float x, float y);
	~Vector2() {}
};