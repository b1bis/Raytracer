#include <iostream>
#include <fstream>

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Color.hpp"

double HitSphere(const Vec3& center, double radius, const Ray& ray)
{
	Vec3 originToCenter{ ray.GetOrigin() - center };
	double a = Vec3::DotProduct(ray.GetDirection(), ray.GetDirection());
	double b = 2.0 * Vec3::DotProduct(originToCenter, ray.GetDirection());
	double c = Vec3::DotProduct(originToCenter, originToCenter) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

Color ComputeColor(const Ray& ray)
{
	if (HitSphere(Vec3(0, 0, -1), 0.5, ray))
		return Color(1, 0, 0);

	Vec3 unitDirection = ray.GetDirection();
	unitDirection.Normalize();
	double t = 0.5 * (unitDirection.GetY() + 1.0);
	return (1 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main(int argc, char** argv)
{
	std::ofstream file{"output.ppm", std::ios::trunc};

	std::ostream& progress = std::cerr;
	std::ostream& output = file;

	constexpr double ratio = 16.0 / 9.0;
	constexpr std::size_t imageWidth = 1000;
	constexpr std::size_t imageHeight = static_cast<std::size_t>(imageWidth / ratio);

	constexpr double viewportHeight = 2.0;
	constexpr double viewportWidth = ratio * viewportHeight;
	constexpr double focalLenght = 1.0;

	Vec3 origin = Vec3::Zero();
	Vec3 horizontal = Vec3(viewportWidth, 0, 0);
	Vec3 vertical = Vec3(0, viewportHeight, 0);
	Vec3 lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLenght);

	output << "P3" << std::endl << imageWidth << ' ' << imageHeight
		<< std::endl << "255" << std::endl;

	for (std::size_t y = 0; y < imageHeight; ++y)
	{
		progress << "Scanline : " << y << std::endl;
		for (std::size_t x = 0; x < imageWidth; ++x)
		{
			double factorX = static_cast<double>(x) / (imageWidth - 1);
			double factorY = static_cast<double>(y) / (imageHeight - 1);
			Ray ray{ origin, lowerLeftCorner + (factorX * horizontal) + (factorY * vertical) - origin };
			Color computed{ ComputeColor(ray) };
			computed.WritePPM(output);
			output << std::endl;
		}
	}

	progress << "Done." << std::endl;

	return EXIT_SUCCESS;
}