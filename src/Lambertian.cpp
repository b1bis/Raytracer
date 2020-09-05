#include "Lambertian.hpp"

bool Lambertian::Scatter(const Ray& ray, const HitInfo& info, Color& attenuation, Ray& scattered) const
{
	Vec3 scatterDirection = info.normal + Vec3::RandomUnitVector();
	scattered = Ray(info.point, scatterDirection);
	attenuation = m_albedo;
	return true;
}
