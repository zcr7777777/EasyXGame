#include "Transform.h"
Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2 operator*(float scalar, const Vector2 &v)
{
	return Vector2(v.x * scalar, v.y * scalar);
}