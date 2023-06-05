#pragma once

#include "Vector2.h"
#include <math.h>

#define PI 3.14159274F
#define DEG2RAD 0.0174532924F
#define RAD2DEG 57.29578F

#define GET_FROM_POSITION_TO_RADIAN(P1, P2) atan2f(P1.y - P2.y, P1.x - P2.x)
#define CONVERT_FROM_RADIAN_TO_ANGLE(RADIAN) (RADIAN * RAD2DEG)
#define CONVERT_FROM_ANGLE_TO_RADIAN(ANGLE) (RADIAN * DEG2RAD)

// 결과 값을 계산한 리턴 값이 필요하기 때문에 람다식을 매크로로 만든다.
#define GET_DISTANCE(P1, P2)\
[](const Vector2& p1, const Vector2& p2)\
{\
	float x = p1.x - p2.x;\
	float y = p1.y - p2.y;\
	return sqrtf(x * x + y * y);\
}(P1, P2)

#define GET_FROM_POSITION_TO_DIRECTION(P1, P2)\
[](const Vector2 &p1, const Vector2& p2)\
{\
	float radian = GET_FROM_POSITION_TO_RADIAN(p1, p2);\
	return Vector2(cosf(radian), sinf(radian));\
}(P1, P2)