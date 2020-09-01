#pragma once

#include "Hittable.hpp"

class Sphere : public Hittable
{
public:
	Sphere() = default;
	Sphere(Vec3 center, double radius) : m_center{ center }, m_radius{ radius } {}
	bool Hit(const Ray& ray, double tMin, double tMax, HitInfo& info) const override;
private:
	Vec3 m_center;
	double m_radius;
};