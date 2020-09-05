#pragma once

#include "Material.hpp"
#include "Color.hpp"

class Metal : public Material
{
public:
	Metal(Color albedo, double fuzz = 0) : m_albedo{ albedo }, m_fuzz{ (fuzz < 1 ? fuzz : 1) } {}
	bool Scatter(const Ray& ray, const HitInfo& info, Color& attenuation, Ray& scattered) const override;
private:
	Color m_albedo;
	double m_fuzz;
};