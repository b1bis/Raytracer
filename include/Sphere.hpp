#pragma once

#include "Hittable.hpp"
#include "Material.hpp"

class Sphere : public Hittable
{
public:
	Sphere() = default;
	Sphere(Vec3 center, double radius, std::shared_ptr<Material> material)
		: m_center{ center }, m_radius{ radius }, m_material{ material } {}
	bool Hit(const Ray& ray, double tMin, double tMax, HitInfo& info) const override;
private:
	Vec3 m_center;
	double m_radius;
	std::shared_ptr<Material> m_material;
};