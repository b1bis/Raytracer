#include "HittableList.hpp"

void HittableList::Clear()
{
	m_hittables.clear();
}

void HittableList::Add(std::shared_ptr<Hittable> hittable)
{
	m_hittables.push_back(hittable);
}

bool HittableList::Hit(const Ray& ray, double tMin, double tMax, HitInfo& info) const
{
	HitInfo tempInfo;
	bool hitAnything = false;
	double closest = tMax;

	for (const auto& hittable : m_hittables)
	{
		if (hittable->Hit(ray, tMin, closest, tempInfo))
		{
			hitAnything = true;
			closest = tempInfo.t;
			info = tempInfo;
		}
	}

	return hitAnything;
}
