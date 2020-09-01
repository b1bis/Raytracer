#pragma once

#include "Vec3.hpp"
#include "Ray.hpp"

class Camera
{
public:
	Camera(double ratio, double viewportWidth, double focalLenght);
	Ray GetRay(double factorX, double factorY) const;
private:
	Vec3 m_origin;
	Vec3 m_lowerLeft;
	Vec3 m_horizontal;
	Vec3 m_vertical;
};