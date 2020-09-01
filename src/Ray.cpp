#include "Ray.hpp"

Vec3 Ray::PointAt(double t) const
{
	return m_origin + m_direction * t;
}
