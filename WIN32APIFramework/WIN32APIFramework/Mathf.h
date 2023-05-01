#pragma once
#include <math.h>
#include "Vector2.h"

#define PI 3.14159274F
#define DEG2RAD 0.0174532924F
#define RAD2DEG 57.29578F

namespace Mathf
{
	float GetFromPositionToRadian(Vector2 p1, Vector2 p2) { return atan2(p1.y - p2.y, p1.x - p2.x); }
	float ConvertFromRadianToAngle(float radian) { return radian * RAD2DEG; }
	float ConvertFromAngleToRadian(float angle) { return angle * DEG2RAD; }
	Vector2 GetFromPositionToDirection(Vector2 p1, Vector2 p2)
	{
		float radian = GetFromPositionToRadian(p1, p2);
		return Vector2(cosf(radian), sinf(radian));
	}
}