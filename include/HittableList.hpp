#pragma once

#include "Hittable.hpp"
#include <vector>
#include <memory>

class HittableList : public Hittable
{
public:
	HittableList() = default;
	void Clear();
	void Add(std::shared_ptr<Hittable> hittable);

	bool Hit(const Ray& ray, double tMin, double tMax, HitInfo& info) const override;
private:
	std::vector<std::shared_ptr<Hittable>> m_hittables;
};