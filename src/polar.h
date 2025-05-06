#pragma once
#include "raylib.h"
#include "rlgl.h"
#include <cmath>
struct Polar
{
public:
	Polar() = default;
	Polar(float angle, float radius) :
		angle{ angle },
		radius{ radius }
	{
	}

	Polar(const Vector2& v) :
		angle{ atan2(v.x,v.y) },
		radius{ sqrtf(v.x * v.x + v.y * v.y) }
	{
	}

	Polar& operator = (const Vector2& v)
	{
		angle = atan2(v.x,v.y);
		radius = sqrtf(v.x * v.x + v.y * v.y);

		return *this;
	}

	operator Vector2() const
	{
		Vector2 v;
		v.x = cos(angle) * radius;
		v.y = sin(angle) * radius;

		return v;
	}

public:
	float angle{ 0 };
	float radius{ 0 };
};
