#include "Camera.hpp"

Camera::Camera(double ratio, double viewportHeight, double focalLenght) : m_origin {0, 0, 0}
{
	double viewportWidth = ratio * viewportHeight;
	m_horizontal = Vec3{ viewportWidth, 0, 0 };
	m_vertical = Vec3{ 0, viewportHeight, 0 };
	m_lowerLeft = m_origin - m_horizontal / 2 - m_vertical / 2 - Vec3(0, 0, focalLenght);
}

Ray Camera::GetRay(double factorX, double factorY) const
{
	return Ray(m_origin, m_lowerLeft + factorX * m_horizontal + factorY * m_vertical);
}
