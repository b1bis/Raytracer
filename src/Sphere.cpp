#include "Sphere.hpp"

bool Sphere::Hit(const Ray& ray, double tMin, double tMax, HitInfo& info) const
{
	Vec3 originToCenter{ ray.GetOrigin() - m_center };
	double a = ray.GetDirection().SquaredLenght();
	double halfB = Vec3::DotProduct(originToCenter, ray.GetDirection());
	double c = originToCenter.SquaredLenght() - m_radius * m_radius;
	double discriminant = halfB * halfB - a * c;
	if (discriminant > 0)
	{
		double root = std::sqrt(discriminant);

		double temp = (-halfB - root) / a;
		if (temp < tMax && temp > tMin)
		{
			info.t = temp;
			info.point = ray.PointAt(temp);
			Vec3 outwardNormal = (info.point - m_center) / m_radius;
			info.NormalFace(ray, outwardNormal);
			info.material = m_material;
			return true;
		}

		temp = (-halfB + root) / a;
		if (temp < tMax && temp > tMin)
		{
			info.t = temp;
			info.point = ray.PointAt(temp);
			Vec3 outwardNormal = (info.point - m_center) / m_radius;
			info.NormalFace(ray, outwardNormal);
			info.material = m_material;
			return true;
		}
	}
	return false;
}
