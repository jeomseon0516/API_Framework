#pragma once
#ifndef __VECTOR2_H__
#define __VECTOR2_H__

struct tagVector2
{
	float x, y;

    tagVector2 operator+(const tagVector2& value)   { return tagVector2(x + value.x, y + value.y); }
    tagVector2 operator+=(const tagVector2& value)  { return tagVector2(x += value.x, y += value.y); }
	tagVector2 operator-(const tagVector2& value)   { return tagVector2(x - value.x, y - value.y); }
    tagVector2 operator-=(const tagVector2& value)  { return tagVector2(x -= value.x, y -= value.y); }
	tagVector2 operator*(const tagVector2& value)   { return tagVector2(x * value.x, y * value.y); }
	tagVector2 operator*(const float& value)	    { return tagVector2(x * value, y * value); }
	tagVector2 operator/(const tagVector2& value)   { return tagVector2(x / value.x, y / value.y); }
	tagVector2 operator/(const float& value)	    { return tagVector2(x / value, y / value); }
                                                    
	bool operator<(const tagVector2& value)		    { return value.x < x && value.y < y; }
	bool operator>(const tagVector2& value)		    { return value.x > x && value.y > y; }
	bool operator<=(const tagVector2& value)	    { return value.x <= x && value.y <= y; }
	bool operator>=(const tagVector2& value)	    { return value.x >= x && value.y >= y; }
	bool operator==(const tagVector2& value)	    { return value.x == x && value.y == y; }
	bool operator!=(const tagVector2& value)	    { return value.x != x && value.y != y; }
                                                    
	// ..Anchor..                                   
	static tagVector2 Zero()				        { return tagVector2(0, 0); }
	static tagVector2 Left()				        { return tagVector2(-1, 0); }
	static tagVector2 Right()				        { return tagVector2(1, 0); }
	static tagVector2 Top()					        { return tagVector2(0, -1); }
	static tagVector2 Bottom()				        { return tagVector2(0, 1); }
	static tagVector2 Center()				        { return tagVector2(0.5f, 0.5f); }

	 tagVector2(float x = 0, float y = 0);
	~tagVector2() {}
}typedef Vector2;
#endif