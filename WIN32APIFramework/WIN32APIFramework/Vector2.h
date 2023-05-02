#pragma once

class tagVector2
{
public:
	float x, y;

	tagVector2 operator+(tagVector2 value) { return tagVector2(x + value.x, y + value.y); }
	tagVector2 operator-(tagVector2 value) { return tagVector2(x - value.x, y - value.y); }
	tagVector2 operator*(tagVector2 value) { return tagVector2(x * value.x, y * value.y); }
	tagVector2 operator*(float value)	   { return tagVector2(x * value, y * value); }

	tagVector2 operator/(tagVector2 value) { return tagVector2(x / value.x, y / value.y); }
	tagVector2 operator/(float value)	   { return tagVector2(x / value, y / value); }

	// ..Anchor..
	static tagVector2 Zero()			   { return tagVector2(0, 0); }
	static tagVector2 Left()			   { return tagVector2(-1, 0); }
	static tagVector2 Right()			   { return tagVector2(1, 0); }
	static tagVector2 Top()				   { return tagVector2(0, -1); }
	static tagVector2 Bottom()			   { return tagVector2(0, 1); }
	static tagVector2 Center()			   { return tagVector2(0.5f, 0.5f); }

	 tagVector2() { *this = tagVector2::Zero(); }
	 tagVector2(float x, float y);
	~tagVector2() {}
}typedef Vector2;