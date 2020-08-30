#pragma once

#include "Vec3.hpp"

class Ray
{
public:
	Ray() = default;
	Ray(Vec3 origin, Vec3 direction) : m_origin {origin}, m_direction {direction} {}

	Vec3 GetOrigin() const { return m_origin; }
	Vec3 GetDirection() const { return m_direction; }

	Vec3 PointAt(double t);
private:
	Vec3 m_origin, m_direction;
};