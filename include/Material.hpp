#pragma once

#include "Ray.hpp"
#include "Color.hpp"
#include "Hittable.hpp"

struct HitInfo;

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const HitInfo& info, Color& attenuation, Ray& scattered) const = 0;
};