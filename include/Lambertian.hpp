#pragma once

#include "Material.hpp"
#include "Color.hpp"

class Lambertian : public Material
{
public:
	Lambertian(Color albedo) : m_albedo{albedo} {}
	bool Scatter(const Ray& ray, const HitInfo& info, Color& attenuation, Ray& scattered) const override;
private:
	Color m_albedo;
};