#pragma once

#include <memory>
#include "Vec3.hpp"
#include "Ray.hpp"

class Material;

struct HitInfo
{
	Vec3 point;
	Vec3 normal;
	double t = 0;
	bool frontFace = false;

	std::shared_ptr<Material> material;

	inline void NormalFace(const Ray& ray, const Vec3& outwardNormal)
	{
		frontFace = Vec3::DotProduct(ray.GetDirection(), outwardNormal);
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual bool Hit(const Ray& ray, double tMin, double tMax, HitInfo& info) const = 0;
};