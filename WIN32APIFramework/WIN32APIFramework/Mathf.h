#pragma once
#ifndef __MATHF_H__
#define __MATHF_H__

#include "Vector2.h"
#include <math.h>

#define PI 3.14159274F
#define DEG2RAD 0.0174532924F
#define RAD2DEG 57.29578F

class Mathf
{
public:
	static float GetFromPositionToRadian(Vector2 p1, Vector2 p2) { return atan2(p1.y - p2.y,  p1.x - p2.x); }
	static float ConvertFromRadianToAngle(float radian) { return radian * RAD2DEG; }
	static float ConvertFromAngleToRadian(float angle) { return angle * DEG2RAD; }
	static float GetDistance(Vector2 p1, Vector2 p2)
	{
		float x = p1.x - p2.x;
		float y = p1.y - p2.y;

		return sqrtf(x * x + y * y);
	}
	static Vector2 GetFromPositionToDirection(Vector2 p1, Vector2 p2)
	{
		float radian = GetFromPositionToRadian(p1, p2);
		return Vector2(cosf(radian), sinf(radian));
	}
};
#endif