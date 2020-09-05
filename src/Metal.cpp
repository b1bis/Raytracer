#include "Metal.hpp"

bool Metal::Scatter(const Ray& ray, const HitInfo& info, Color& attenuation, Ray& scattered) const
{
	Vec3 reflected = Vec3::Reflect(ray.GetDirection().GetNormalized(), info.normal);
	scattered = Ray(info.point, reflected + m_fuzz * Vec3::RandomUnitVector());
	attenuation = m_albedo;
	return Vec3::DotProduct(scattered.GetDirection(), info.normal) > 0;
}
